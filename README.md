# Y.A.R.T
### Yet Another Random Testbench (Or NOT)

For most of the challenges where we need to decide the size of a data structure, we shall fix n = 10^8

## Setup
For Rust, we shall use rustup to set up the enviornment. We will be using the stable channel of Rust (as fat as possible), when we need nighly features, we shall mention it as such.

Set up rust :
```bash
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```
The Rust projects can be run using 
RUSTFLAGS="-C target-cpu=native" cargo build --release
```
OR
```bash
rustc -C debuginfo=0 -C opt-level=3 -C target-cpu=native (filename)
```

#### No pointers for havind C++ and python set up!
