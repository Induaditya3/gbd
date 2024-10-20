# Cheat Sheet

## Break conditionally on an argument

  - `b <function>`  eg `b glSetClearColor`
  - `condition <breakpoint_number> <argument>==<no>`  eg `condition 2 mask==5`
  - `condition <breakpoint_number> <argument>==<no>`  eg `condition 2 mask==0xaabbccff

## print arguments in hex or directly print argument registers:

  - `info args`
  - `print /x variable_name`
  - `print /x $rdi` assuming x86-64 calling conventions

## Break conditionally on the current function's caller

  - `b <function>`  eg `b Flip`
  - `info b`
  - `condition <breakpoint_number> $_caller_is ("<function>")  eg condition 2 $_caller_is ("SwapBuffers")
