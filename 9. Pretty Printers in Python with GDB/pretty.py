# Run 'source pretty.py' in gdb

# STEP (1) -- create a pretty printer
#
# This is our pretty printer class.
# You will implement 'one' pretty printer
# per object type that you want to pretty print
# (otherwise, gdb defaults to the normal behavior)
class GameObjectTypePrinter:
    # Constructor in Python
    def __init__(self,val):
        self.val = val

    # Perform the pretty printing
    def to_string(self):
        text =  "\n\tid   : " + str(self.val['id'])
        text += "\n\tmName: " + str(self.val['mName'])
        text += "\n\tmData: " + str(self.val['mData']['SomeField'])
        return text
# STEP (2) -- add pretty printer to your lookup
#
# This function will return the correct type
# of object for us -- i.e. construct the right
# pretty printer.
def TypeLookup(val):
    if str(val.type) == "GameObjectType":
        return GameObjectTypePrinter(val)
    # If we find nothing, then return 'None'.
    # (Effectively this is 'null')
    return None

# STEP (3) -- Call '.append' one time
#
# Finally we append to our lookup function
# to gdb's lookup function list
gdb.pretty_printers.append(TypeLookup)



    
