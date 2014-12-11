
## Tannus - Comprehensive Toolset with a Focus on JavaScript ##

The Tannus library provides extensive tools for various types of Haxe development,
primarily those which involve the use of JavaScript.  Tannus can be used for Node apps, client-side JavaScript, Chrome extensions,
etc.


### The Inspiration ###
I was inspired to create Tannus by the need for a library which allowed me have a single JavaScript file for a WebApp, and 
have only certain portions execute on any given page.  Thus was written the `tannus.Application`, `tannus.core.Route`,
`tannus.core.Router`, and `tannus.core.Page` classes.  This allows one or more "Applications" to be written within a single JS file.
Consider the following example:

    /*
    ==  Demo.hx  ==
    */
    import tannus.Application;
    import tannus.core.Page;
    import mypages.AboutUs;
    
    class Demo extends Application {
      public function new():Void {
        super();
        
        createRoutes();
      }
      
      //- method to initialize the "Route"s for this app
      public function createRoutes():Void {
        //- "Route"s can be created with just an event-listener
        route('home', function(page : Page):Void {
          trace( "You have navigated to the Home Page" );
        });
        
        //- or, with a class
        route('about-us', null, AboutUs);
      }
      
      //- Now define the 'main' function which will kick off this app
      public static function main():Void {
        //- create an instance of "Demo"
        var app:Demo = new Demo();
        
        //- start the app
        app.start();
      }
    }

Now, for the `mypages.AboutUs` class mentioned in the code:

    /*
     == AboutUs.hx ==
    */
    package mypages;
    
    import tannus.core.Route;
    import tannus.core.Page;
    
    class AboutUs extends Page {
        public function new(route : Route):Void {
            super( route );
            
            doStuff();
        }
        
        //- Method that would normally "do stuff"
        public function doStuff():Void {
            trace( "Navigated to About-Us page, doing stuff now" );
        }
    }
    
That's how you create a simple two-page Tannus application!  My documentation is rather lackluster (sorry) as of right now, but
to learn more you may feel free to dig around the code.  I'm going to try to write some docs in the wiki sometime soon.
