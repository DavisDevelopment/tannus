package tannus.core;

import tannus.core.SinglePageApplication;
import tannus.core.Page;
import tannus.core.Route;
import tannus.core.Component;
import tannus.core.GeneratedPage;

import tannus.io.Signal;

import tannus.dom.Element;
import tannus.dom.widgets.BaseWidget;

class BaseContentController extends Page {
	/* Constructor Function */
	public function new(route : Route):Void {
		super(route);
		
		defaultPage = GeneratedPage;
		active = null;

		__initContentController();
	}

/* === Instance Methods === */

	/**
	  * Initialize [this] BaseContentController
	  */
	private function __initContentController():Void {
		base = new Element('<div></div>');
		base.addClass( 'row' );

		on('open', function(me) {
			cast(application, SinglePageApplication).before_ccBoot.dispatch( this );
		});
	}

	/**
	  * Custom 'open' behavior
	  */
	override public function open():Void {
		super.open();
	
		//- Create and instance of the default starting Page
		var landing:GeneratedPage = Type.createInstance(defaultPage, []);
		
		//- open it
		openPage( landing );	
	}

	/**
	  * Method which "open"s a GeneratedPage
	  */
	public function openPage(page : GeneratedPage):Void {
		//- if a Page is already being displayed, destroy it
		if (active != null) {
			active.destroy();
		}
		
		//- Tell the Page where to put their content
		page.base = base;

		//- Tell it to generate its content
		page.open();

		//- mark it as 'active'
		active = page;
	}

/* === Instance Fields === */

	/**
	  * The default Page class to display first
	  */
	public var defaultPage:Class<GeneratedPage>;

	/**
	  * The Page currently being displayed
	  */
	public var active:GeneratedPage;

	/**
	  * The primary pane in which "page"s can display their content
	  */
	public var base:Element;
}
