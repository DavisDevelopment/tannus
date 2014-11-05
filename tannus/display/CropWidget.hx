package tannus.display;

import tannus.display.Stage;
import tannus.display.Entity;
import tannus.display.Image;
import tannus.display.CropCorner;
import tannus.display.Cropbox;

import tannus.ui.FileInput;
import tannus.utils.Buffer;
import tannus.core.Object;

class CropWidget extends Entity {
	public var image:Image;
	public var box:Cropbox;
	
	public function new(ref:Dynamic, ?options:CropWidgetOptions):Void {
		super();
		
		this.options = (options != null ? options : {});
		this.image = new Image(ref);
		addAsset(image);
		this.box = new Cropbox(image);
		addAsset(box);

		on('activate', init.bind());
	}

	public function init():Void {
		this.stage.add(this.image);
		this.stage.add(this.box);
	}

	public function bindToInput(ref:Dynamic):Void {
		var finput:FileInput = new FileInput(ref);

		finput.on('file-loaded', function(file) {
			trace(file);
			if (~/image/.match(file.type)) {
				var data:Buffer = cast file.data;
				var imgUrl:String = data.toDataURI(file.type);
				var img:Image = new Image('<img src="$imgUrl" />');
				
				this.image.destroy();
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

private typedef CropWidgetOptions = {
	icons : Null<Object>
};
