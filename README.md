# dng - danger perceptron

- runs on Linux.
- Uses a perceptron detector and prints DANGER.

## Build
- Use the included makefile with the make utility and a C compiler.
- make install will copy to /usr/local/bin to make it available. You
  need "sudo make install" to access the target directory.
- The gmake file format for the Makefile is not the BSD make format.

## Run
- Optional Argument
-- -q disables the printing which is silly but it is there.

- Example
-- while true; do ./dng | espeak -a200; done 
-- This works on Linux if you install espeak
-- Other text to speech programs exist.

