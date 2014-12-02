all: js

js:
	haxe-nightly ./build-files/build-js.hxml && node testing/promiscript.js

neko:
	haxe-nightly ./build-files/build-neko.hxml && neko testing/promiscript.n

compress: haxe
	cd ..; cd lib; uglifyjs -o tannus.min.js tannus.raw.js

test: haxe
	cd ..; cd lib; nodejs tannus.raw.js
