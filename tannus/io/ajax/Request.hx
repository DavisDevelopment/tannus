package tannus.io.ajax;

/* Tannus Core Imports */
import tannus.core.Destructible;

/* Tannus IO Imports */
import tannus.io.Ptr;
import tannus.io.Byte;
import tannus.io.ByteArray;
import tannus.io.Signal;

import tannus.io.ajax.ReadyState;

/* Tannus Util Imports */
import tannus.utils.Maybe;
import tannus.utils.Buffer;
import tannus.utils.Promise;

/* Tannus AJAX Imports */
import tannus.io.ajax.Tools;

class Request {
	/**
	  * Constructor Function
	  */
	public function new(?address:Maybe<String>):Void {
	
		//- Create my NReq
		req = js.Browser.createXMLHttpRequest();

		//- 'data' defaults to [null]
		data = null;

		//- 'url' is either [adress] OR an empty String
		url = address.or( "" );

		//- 'method' defaults to 'GET'
		method = 'GET';

		//- initialize the Signal which handles incoming updates to the status of [this] Request
		readyStateChange = new Signal();

		done = new Signal();

		ready = new Signal();

		failed = new Signal();

		_prepare();
	}

/* === Instance Fields === */

	/**
	  * Private reference to the [NReq] Instance [this] Request operates on
	  */
	private var req : NReq;


	/**
	  * The Data to be Sent by [this] Request
	  */
	public var data : Dynamic;

	
	/**
	  * The Destination you'll be sending that data to
	  */
	public var url : String;


	/**
	  * The method of [this] Request
	  */
	public var method : String;

	
	/**
	  * Signal which fires when [this] Request's 'readyState' field changes
	  */
	public var readyStateChange : Signal<ReadyState>;

	
	/**
	  * Signal which fires when [this] Request has declared itself "complete" (this could be due to either success OR failure)
	  */
	public var done : Signal<Bool>;
	
	/**
	  * Signal which fires when [this] Request has declared itself "ready" (it has successfully loaded it's content)
	  */
	public var ready : Signal<Dynamic>;

	/**
	  * Signal which fires when [this] Request has failed to load
	  */
	public var failed : Signal<Dynamic>;


/* === Computed Instance Fields === */


	/**
	  * The current state of [this] Request
	  */
	public var readyState(get, never) : ReadyState;
	private inline function get_readyState() : ReadyState {
		return (getMyReadyState());
	}


	/**
	  * The current response-type of [this] Request
	  */
	public var responseType(get, set) : String;
	private inline function get_responseType() : String {
		return (responseTypeAsString());
	}
	private inline function set_responseType(restype : String):String {
		setMyResponseType( restype );
		return responseType;
	}

	/**
	  * Reference to [this] Request's 'response' field
	  */
	public var response(get, never) : Dynamic;
	private inline function get_response() : Dynamic {
		return (req.response);
	}

/* === Instance Methods === */

	/**
	  * 'open' method - sets [this] Request's 'method' and 'url' fields
	  */
	public function open(method:String, url:String):Void {
		//- set [this] Reqest's 'method' field
		this.method = method;

		//- set [this] Request's 'method' field
		this.url = url;

		req.open(method, url);
	}

	/**
	  * 'send' method - sets [this] Request's 'data' field and sends [req]
	  */
	public function send(?sdata : Maybe<Dynamic>):Void {
		//- set [this] Request's 'data' field
		data = (data != null ? sdata.or(data) : sdata);

		data = Tools.toHttpSafe( data );

		req.send( data );
	}

	/**
	  * "abort" [this] Request
	  */
	public function abort():Void {
		req.abort();
	}
	
	/**
	  * Retrieve all Http-Headers attached to the Response
	  */
	public function getAllResponseHeaders():String {
		
		return (req.getAllResponseHeaders());
	}

	/**
	  * Initialization Method which prepares the interface to the native NReq instance
	  */
	private function _prepare():Void {
		_forwardEvents();
	}

	/**
	  * Private Method which forwards all Events occurring on [req] to [this]
	  */
	private function _forwardEvents():Void {

		//- bind the 'onreadystatechange' event
		req.onreadystatechange = (function(e : Dynamic):Void {
			//- to [this] Request's readyStateChange Signal
			readyStateChange.dispatch( this.readyState );
		});

		
		/* == Forward the Load and Error Events to our Done Event == */
		req.onload = (function(e : Dynamic) {
			done.dispatch( true );
			
			ready.dispatch(this.response);
		});


		req.onerror = (function(e : Dynamic) {
			done.dispatch( false );

			failed.dispatch( e );
		});
	}


	/**
	  * Convert [req]'s 'readyState' field to a ReadyState value
	  */
	private function getMyReadyState():ReadyState {
		//- Get the 'readyState' of [req]
		var rs:Int = req.readyState;
		
		//- Translate that into a ReadyState value
		return (switch ( rs ) {
			//- 0 => UNSENT
			case 0: ReadyState.Unsent;

			//- 1 => OPENED
			case 1: ReadyState.Opened;

			//- 2 => HEADERS_RECEIVED
			case 2: ReadyState.HeadersReceived;

			//- 3 => LOADING
			case 3: ReadyState.Loading;

			//- 4 => DONE
			case 4: ReadyState.Done;

			//- Anything Else
			default:
				throw 'WhatTheFuckError: Translating XMLHttpRequest\'s "readyState" field (0-4 range expected), but got $rs';
		});
	}

	/**
	  * Convert [req]'s 'responseType' field to a ResponseType value
	  */
	private function getMyResponseType():ResponseType {
		var rt:String = (req.responseType);
		rt = rt.toLowerCase();

		return responseTypeFromString( rt );
	}

	/**
	  * Self-Explanatory
	  */
	private function setMyResponseType(rt : String):Void {
		var mrt:ResponseType = responseTypeFromString( rt );
		var rrt:String = responseTypeToString( mrt );

		req.responseType = rrt;
	}

	/**
	  * Convert ResponseType to String
	  */
	private function responseTypeAsString():String {
		var rt:ResponseType = getMyResponseType();

		return (switch (rt) {
			//- String
			case ResponseType.RTString: return "string";


			//- ArrayBuffer
			case ResponseType.RTArrayBuffer: return "arraybuffer";


			//- Blob
			case ResponseType.RTBlob: return "blob";

			//- Document
			case ResponseType.RTDocument: return "document";

			//- JSON
			case ResponseType.RTJson: return "json";
		});
	}

	/**
	  * Convert ResponseType [restyp] to String
	  */
	private function responseTypeToString(restyp : ResponseType):String {
		var rt = restyp;

		return (switch (rt) {
			//- String
			case ResponseType.RTString: return "string";


			//- ArrayBuffer
			case ResponseType.RTArrayBuffer: return "arraybuffer";


			//- Blob
			case ResponseType.RTBlob: return "blob";

			//- Document
			case ResponseType.RTDocument: return "document";

			//- JSON
			case ResponseType.RTJson: return "json";
		});
	}

	/**
	  * Convert String [restype] to a 
	  */
	private function responseTypeFromString(restype : String):ResponseType {
		var rt:String = restype;

		return (switch (rt) {
			//- String Type
			case "", "text": ResponseType.RTString;

			//- ArrayBuffer Type
			case "arraybuffer": ResponseType.RTArrayBuffer;

			//- Blob Type
			case "blob": ResponseType.RTBlob;

			//- Document Type
			case "document": ResponseType.RTDocument;

			//- JSON Type
			case "json": ResponseType.RTJson;

			default:
				     throw 'UnknownResponseTypeError: "$rt" is not a recognized ResponseType!';
		});

	}
}

#if js

/**
  * Typdef which acts as an alias to XMLHttpRequest
  */
private typedef NReq = js.html.XMLHttpRequest;

#end
