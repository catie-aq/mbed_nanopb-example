# NanoPb client example

[![pipeline status](https://gitlab.com/catie_6tron/nanopb-example/badges/master/pipeline.svg)](https://gitlab.com/catie_6tron/nanopb-example/commits/master)

**Important note**: This example _may not work_ unless you properly configured
Protocol Buffers and NanoPb on your platform.

This application performs the serialization and deserialization of simulated
environment data (stub). 

## Usage

* Deploy the libraries with `mbed deploy`
* Compile the `.proto` file: 

    ```sh 
    protoc
        --plugin=protoc-gen-nanopb=<path_to_nanopb_generator_protoc-gen-nanopc>
        --nanopb_out=. environment.proto
    ```

* Compile the program for your target: `mbed compile`
* Read from serial port: `cat /dev/ttyUSBx` to verify the correct behavior
