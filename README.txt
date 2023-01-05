42brightness
Script to manage screen brightness
Options :
42brightness : displays current brightness
42brightness --format : displays current brightness (<value> <percentage> <max value>), so that it's easier to be used by another program
42brightness -h / --help : displays this text
42brightness <N> : (in/de)creases brightness of <N> percents
42brightness --value <N> : (in/de)creases brightness of <N>
42brightness --max : sets the max brightness (same as 42brightness --set 100)
42brightness --set <N> : sets brightness to <N>%
42brightness --set-value <N> : sets brightness to <N>
Be careful to not set too small values !
Returns codes :
	- 0 : OK
	- 21 : operation aborted (when low brightness asked and user is warned and cancels)
	- 42 : bad argument(s)
	- 84 : cannot open system files (program must run as root)

IMPORTANT NOTE :

For now, it works only for computers with some Intel hardware (because of the directory I open have a different name otherwise), it'll be fixed later.
