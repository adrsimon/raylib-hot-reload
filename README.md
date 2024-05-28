# raylib-hot-reload

A hot-reload system in C implemented to support the use of Raylib.

## Inspiration

This code was implemented while watching [Tsoding's](https://youtube.com/@tsodingdaily) videos'. I just thought I'd implement it myself to understand it and use in in future projects. He is the creator of this.

## Usage

0. Build the builder.
```shell
gcc -o nob nob.c
```

1. Build the plugin using the builder.
```shell
./nob
```

2. Launch your app.
```shell
./main
```

3. Make modifications to the plugin and rebuild the plugin.
```shell
./nob
```

4. Just press R inside your active app window after rebuilding the plugin. No need to close it and `./main` again.
