#!/bin/csh
#
# Like build_startup_file.csh, but for the mac app...

if( $#argv != 1 && $#argv != 2 ) then
  echo 'usage:  ./mac_build_startup.csh demo [test]'
  exit
endif

set flavor=$1
if( $flavor != demo ) then
  echo './mac_build_startup.csh:  bad flavor requested:  $flavor'
  echo 'usage:  ./mac_build_startup.csh <flavor> [test]'
  echo 'known flavors:  demo'
  exit
endif

set test_mode=0
if( $#argv == 2 ) then
  if( $2 == test ) then
    set test_mode=1
  else
    echo 'usage:  ./mac_build_startup.csh <flavor> [test]'
    echo 'Second argument must be "test" if present'
    exit
  endif
endif

# Make a single encrypted file containing the startup macros
# and the startup script.
#
# We begin with coq_startup.scr

set outfile=mac_startup.scr
set encfile=mac_startup.enc

cat < /dev/null > $outfile

echo "If var_exists(startup_file_read) 'exit_file'" >> $outfile
echo 'advise "in startup file..."' >> $outfile

set suffix=mac

# not yet
#set sfile=/usr/local/share/coq/macros/startup/coq.scr
#if( -e $sfile) then
#  cat $sfile >> $outfile
#else
  # macros from system subdir
  set subdir=system
  set file_list=( builtin msgs vars files ios_helper )
  source add_files.csh
  
  set subdir=data
  #size.scr
  set file_list=( ascii decl hips )
  source add_files.csh
  
  # files from gencomp.scr
  set subdir=compute
  set file_list=( funcs chains )
  source add_files.csh

  set subdir=opengl
  set file_list=( icos )
  source add_files.csh

  set subdir=view
  # dpysize.scr
  set file_list=( common luts view ios_plot plotsupp )
  source add_files.csh
  
  set subdir=gui
  set file_list=( ui )
  source add_files.csh
  
  set subdir=numrec
  set file_list=( fit_polynomial svd norm_coords )
  source add_files.csh

#endif

set subdir=cocoa
set file_list=( menu_bar )
source add_files.csh
cat >> $outfile << EOF

If !var_exists(DISPLAY_WIDTH)
  "Set DISPLAY_WIDTH 200 Set DISPLAY_HEIGHT 200"

max_warnings -1

echo "initializing subsystems..."
view quit		# init viewer subsystem
data quit		# init data subsystem
compute quit		# init veclib

Set chatty 1
Init_Test_Menus

Set macro_dir /usr/local/share/quip/macros

EOF
# the max_warnings line was in the fragment above...
echo "advise 'startup.scr: max_warnings set to -1 in mac_build_startup.csh'" >> $outfile
echo "platforms list_all show quit" >> $outfile

if( $flavor == demo ) then
  echo No flavor-specific files known...
endif

echo File $outfile complete, encrypting...

# We tried using 'which' to determine the presence of quip,
# but we couldn't eliminate the annoying "quip:  command not found"
# message from the output...

#set q=`which quip` >& /dev/null
#echo status = $status
#if( status != 0 ) then
#  quip binary not found, not encrypting startup file.
#  if( -e $encfile ) then
#    /bin/rm $encfile
#  endif
#  # make a zero-len file so the bundle will build
#  touch $encfile
#else
#  quip $outfile $encfile < encrypt_file.scr
#endif

quip $outfile $encfile < encrypt_file.scr >& /tmp/enc_errors
if( $status != 0 ) then
  echo Problem encrypting: `cat /tmp/enc_errors`
  /bin/rm /tmp/enc_errors
  echo Creating zero-length encrypted file.
  if( -e $encfile ) then
    /bin/rm $encfile
  endif
  # make a zero-len file so the bundle will build
  touch $encfile
endif


