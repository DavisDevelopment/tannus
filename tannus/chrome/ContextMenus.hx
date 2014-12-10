package tannus.chrome;

class ContextMenus {
	public static function create(props:Dynamic, ?onclick:Dynamic):Void {

		(untyped __js__('chrome.contextMenus')).create(props, onclick);
	
	}
}
