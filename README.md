# NanoPb client example


This application performs the serialization and deserialization of simulated environment data (stub).

## Usage

- Deploy the libraries with `mbed deploy`

- (Optional) Compile the `.proto` file:

  ```shell
  protoc
      --plugin=protoc-gen-nanopb=<path_to_nanopb_generator_protoc-gen-nanopc>
      --nanopb_out=. environment.proto
  ```

- Compile the program for your target: `mbed compile`

- Read from serial port: `cat /dev/ttyUSBx` to verify the correct behavior
