package tannus.display;

import tannus.display.Stage;
import tannus.display.Entity;
import tannus.display.Image;
import tannus.display.CropCorner;
import tannus.display.Cropbox;

import tannus.ui.FileInput;
import tannus.ui.Canvas;
import tannus.utils.Buffer;
import tannus.utils.Pointer;
import tannus.core.Object;

@:keep
class CropWidget extends Entity {
	public var image:Null<Image>;
	public var box:Null<Cropbox>;
	public var options:CropWidgetOptions;
	
	public function new(ref:Dynamic, ?options:CropWidgetOptions):Void {
		super();
		
		if (options == null)
			options = new CropWidgetOptions();

		this.options = options;
		if (tannus.ui.JQuery.select(ref).at(0) != null) {
			this.image = new Image(ref);
			addAsset(image);
			this.box = new Cropbox(image);
			addAsset(box);
		}

		on('activate', init.bind());

		on('accept', accept.bind(_));
	}

	public function init():Void {
		if (image != null && box != null) {
			this.stage.add(this.image);
			this.stage.add(this.box);
		}

		var boxPtr:Pointer<Null<Cropbox>> = Pointer.literal(this.box);

		if (this.options.acceptButton != null) {
			this.options.acceptButton.on('click', function(e:Dynamic):Void {
				var bx:Null<Cropbox> = boxPtr.get();
				if (bx != null) {
					bx.crop();
				}
			});
		}
	}

	public function accept(can:Canvas):Void {
		if (this.options.accept != null) {
			this.options.accept(can);
		}
	}

	public function grab(callb:Canvas -> Void):Void {
		callb(this.image.crop(this.box.box));
	}

	public function bindToInput(ref:Dynamic):Void {
		var finput:FileInput = new FileInput(ref);
		trace(finput);

		finput.on('file-loaded', function(file) {
			trace(file);
			if (~/image/.match(file.type)) {
				var data:Buffer = cast file.data;
				var imgUrl:String = data.toDataURI(file.type);
				var img:Image = new Image('<img src="$imgUrl" />');
				
				if (this.image != null)
					this.image.destroy();

				if (this.box != null)
					this.box.destroy();

				this.image = img;
				addAsset(this.image);
				this.stage.add(this.image);

				this.box = new Cropbox(img);
				addAsset(this.box);
				this.stage.add(this.box);
			}
		});
	}
}

private class CropWidgetOptions {
	public var icons : Null<Object>;
	public var accept : Null<Canvas -> Void>;
	public var acceptButton : Null<Dynamic>;

	public function new():Void {
		this.icons = new Object({});
		this.accept = null;
		this.acceptButton = null;
	}
}
