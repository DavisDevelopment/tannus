all: haxe

haxe:
	haxe-nightly ./build-files/build-js.hxml && node testing/promiscript.js

compress: haxe
	cd ..; cd lib; uglifyjs -o tannus.min.js tannus.raw.js

test: haxe
	cd ..; cd lib; nodejs tannus.raw.js
