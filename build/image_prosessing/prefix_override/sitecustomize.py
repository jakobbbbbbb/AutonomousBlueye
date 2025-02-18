import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/ovsj/Code/AutonomousBlueye/install/image_prosessing'
