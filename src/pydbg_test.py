from pydbg import *
from pydbg.defines import *

def hidepydbg(pid):
    h = CDLL('hidepydbg.dll')
    h.hide_debug(pid)

# This is our access violation handler
def create_prcess_handler(dbg):
    hidepydbg(dbg.pid)
    dbg.bp_set_hw(0x0047673C, 1, HW_ACCESS, handler=hwdp_handler)
    return DBG_CONTINUE

def hwdp_handler(dbg):
    print("found hardware breakpoint")
    dbg.hardware_breakpoint_hit = None
    print dbg.dump_context()
    return DBG_CONTINUE

dbg = pydbg()
dbg.load(r"C:\Program Files\Skype\Phone\Skype.exe");
dbg.set_callback(CREATE_PROCESS_DEBUG_EVENT, create_prcess_handler);
dbg.run()
