all: haxe compress

haxe:
	haxe build.hxml

compress: haxe
	cd ..; cd lib; uglifyjs -o tannus.min.js tannus.raw.js

test: haxe
	cd ..; cd lib; nodejs tannus.raw.js