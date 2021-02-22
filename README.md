# Manna (wrapper)
HTTP/2 server library for Manna.
This library acts as a wrapper to help standardize communication with other server libraries.
In other words, if we ever decide to depend on another server library (or even decide to build our own), any application making use of this library will not require changing its code (it will only need to recompile).

## Third-party dependencies

 * nghttp2
 * libboost (v1.6.7)
