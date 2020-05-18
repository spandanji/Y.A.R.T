# Y.A.R.T
### Yet Another Random Testbench (Or NOT)

For most of the challenges, where we need to decide the order of input, we shall fix n = 10^8.

## Platform
All the testing would be done on a linux distributuion, so instructions for setup or running the code will not work for any other platforms as of now.

## Setup
For Rust, we shall use rustup to set up the enviornment. We will be using the stable channel of Rust (as much as possible), when we need nighly features, we shall mention it as such.

Set up rust :
```bash
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```
The Rust projects can be run using 
```bash
RUSTFLAGS="-C target-cpu=native" cargo build --release
```

OR

```bash
rustc -C debuginfo=0 -C opt-level=3 -C target-cpu=native (filename)
```

#### No pointers for having C++ and python set up!
