# nanopb-client-example

**Important note**: This example _may not work_ unless you properly configured Protocol Buffers and nanopb on your platform.

This application performs the serialization and _deserialization_ of simulated environment data (stub). 

## Usage

* Deploy the used libraries: `mbed deploy`

* Compile the `.proto` file: 

```sh
protoc --plugin=protoc-gen-nanopb=<path_to_nanopb_generator_protoc-gen-nanopc> --nanopb_out=. environment.proto
```

* Compile the program for your target: `mbed compile`

* Read from serial port: `cat /dev/ttyUSB?` to verify the correct behavior.
