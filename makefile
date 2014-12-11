all:
	haxe ./build.hxml

js:
	haxe ./build-files/build-js.hxml && node testing/promiscript.js

neko:
	haxe ./build-files/build-neko.hxml && neko testing/promiscript.n

demo:
	haxe -main Demo -php testing/demo-php/
	haxe -main Demo -python testing/demo.py

	echo ' === PHP === '
	php testing/demo-php/index.php

#	echo ''
#	echo ' === Python === '
#	python3 testing/demo.py


compress: haxe
	cd ..; cd lib; uglifyjs -o tannus.min.js tannus.raw.js

test: haxe
	cd ..; cd lib; nodejs tannus.raw.js
