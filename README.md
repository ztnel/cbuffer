# Circular Buffer

Modified: 2023-01

A simple generic circular buffer implementation.

## Highlights
1. Configurable for any statically allocated buffer provided its size and element width.
2. Values are copied to buffer to avoid variables being deallocated as a result of a scope change.
3. Buffer overflow and underflow protection.
4. Designed for use on a single process micro embedded system. No data synchronization code is implemented.
5. The buffer access algorithms sacrifice time complexity for a lower runtime memory footprint.
6. The code sacrifices code size for execution efficiency (use of `inline` functions for internal buffer state verification).

## License
Permission to use this software is granted under the terms of the [MIT License](LICENSE)