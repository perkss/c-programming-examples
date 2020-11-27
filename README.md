#To Compile

# Glib Examples

To run the GLIB examples you require the Library glib-2.0. 

One of the pain points of C is linking libraries and using them, so how do we 
get glib into our project the simple recommended way is to use `pkg-config` like so

```shell script
gcc `pkg-config --cflags --libs glib-2.0` -o ex-compile ex-compile.c
```

To fully understand getting the library we can link it using the common `-l` approach.

We can can use `pkg-config` to find the locations and the dependent libraries required to get the library imported.

`pkg-config` will commonly be installed, but on a mac if not use 

```shell script
brew install pkg-config
```

Then you can search for the required library paths and header paths to compile your example with the 
required `glib-2.0` library. This does the equivalent of the command above specifying the `--cflags --libs` 
part.

```shell script
$ pkg-config --cflags glib-2.0
-I/usr/local/Cellar/glib/2.56.0/include/glib-2.0 -I/usr/local/Cellar/glib/2.56.0/lib/glib-2.0/include -I/usr/local/opt/gettext/include -I/usr/local/Cellar/pcre/8.44/include
$ pkg-config --libs glib-2.0
-L/usr/local/Cellar/glib/2.56.0/lib -L/usr/local/opt/gettext/lib -lglib-2.0 -lintl -Wl,-framework -Wl,CoreFoundation
```

Then the results of these two commands can be used as so
```shell script
gcc ex-compile.c -o compile -lglib-2.0 -lintl -I/usr/local/Cellar/glib/2.56.0/include/glib-2.0 -I/usr/local/Cellar/glib/2.56.0/lib/glib-2.0/include
```


# Libcurl Example Against ElasticSearch
A nice example of very basic interaction with ElasticSearch via Rest and libCurl with C.

# Programming Pearls Examples
You will find code examples and solutions for programming pearls in the relevant directories. 

To run:
```shell script
gcc <filename> -o <wanted-name>
```

# Weak References

