
<HTML>
<HEAD>
<TITLE>Homework #1 - CSCI 531, Spring 2015</TITLE>
<LINK HREF="../../cs531bc.css" REL="stylesheet" TYPE="text/css">
<LINK REV="made" HREF="mailto:bill.cheng@acm.org"></HEAD>
<BODY BGCOLOR="#FFFFFF" LINK="#D02090" VLINK="#996600" ALINK="#990000">

<TABLE BORDER=0 CELLPADDING=0 CELLSPACING=0 WIDTH=100%>
<TR><TD ALIGN=CENTER VALIGN=TOP WIDTH=112>
    <!-- COL 1, should be identical to all other pages here -->
    <TABLE BORDER=0 CELLPADDING=0 CELLSPACING=0 WIDTH=113>
    <TR><TD ALIGN=CENTER VALIGN=TOP WIDTH=112>
        &nbsp;
        </TD>
    </TR>
    <TR><TD ALIGN=CENTER VALIGN=TOP WIDTH=112>
        <A HREF="http://www.cs.usc.edu/"><IMG SRC="../../images/usctommy.gif"
            ALT="USC CSD Home" BORDER=0></A>
        <!-- BR>&nbsp;<BR -->
        <!-- IMG SRC="images/small-uc.gif" BORDER=0 -->
        </TD>
    </TR>
    </TABLE>
    </TD>
    <!-- TD ALIGN=LEFT VALIGN=TOP WIDTH=13 -->
    <!-- COL 2, should be identical to all other pages here -->
        <!-- IMG SRC="images/spacer.gif" HEIGHT=1 WIDTH=13 -->
    <!-- /TD -->
    <TD ALIGN=LEFT VALIGN=TOP>
    <!-- COL 3, every page should be different -->
        <TABLE BORDER=0>
        <!-- Page Header -->
        <TR><TD ALIGN=LEFT VALIGH=TOP>
                <A HREF="../../">Spring 2015<A>
            </TD>
            <TD ALIGN=RIGHT VALIGH=TOP>
                <A HREF="../../">CSCI 531</A><BR>
            </TD>
        </TR>
        <BR>
        <!-- Page Title -->
        <TR><TD COLSPAN=3 ALIGN=CENTER>
                <H2>Homework #1</H2>
                <H4>(50 points total)</H4>
                <H2>Manipultaing Bits</H2>
                <B><I>Due 11:45PM
                1/30/2015 (firm)</I></B>
                <!--
                <H3><FONT COLOR="red"><I>(Under Construction -
                    Anything Can Change without Notice)</I></FONT></H3>
                  -->
            </TD>
        </TR>
        <TR><TD>&nbsp;</TD></TR>
        <!-- Section -->
        <TR><TD COLSPAN=3 ALIGN=LEFT BGCOLOR="#000000" WIDTH=100%>
                <FONT COLOR="#ffffff"><A
                NAME="intro"><B>Assignment</B></A></FONT>
            </TD>
        </TR>
        <!-- Top Section -->
        <TR><TD COLSPAN=3 ALIGN=LEFT>
The purpose of this assignment is to get you up to speed
with manipulating bits in memory and files.

<P>

<A HREF="#submit">Electronic submissions</A> only.
            </TD>
        </TR>
        <TR><TD>&nbsp;</TD></TR>
        <!-- Section -->
        <TR><TD COLSPAN=3 ALIGN=LEFT BGCOLOR="#000000" WIDTH=100%>
                <FONT COLOR="#ffffff"><A
                NAME="syntax"><B>Compiling</B></A></FONT>
            </TD>
        </TR>
        <!-- Top Section -->
        <TR><TD COLSPAN=3 ALIGN=LEFT>
Please use a <TT>Makefile</TT> so that when the grader simply enters:
    <PRE>
    make hw1</PRE>
an executable named <B>hw1</B> is created.
Please make sure that your submission conforms to
<A HREF="../../makefile.html#requirements">other
general compilation requirements</A>.
            </TD>
        </TR>
        <TR><TD>&nbsp;</TD></TR>
        <!-- Section -->
        <TR><TD COLSPAN=3 ALIGN=LEFT BGCOLOR="#000000" WIDTH=100%>
                <FONT COLOR="#ffffff"><A
                NAME="syntax"><B>Commandline Syntax & Program
                Output</B></A></FONT>
            </TD>
        </TR>
        <!-- Top Section -->
        <TR><TD COLSPAN=3 ALIGN=LEFT>
The commandline syntax for <B>hw1</B> is as follows:

<PRE>
    <B>hw1</B> <B>hexdump</B> [file]
    <B>hw1</B> <B>enc-base64</B> [file]
    <B>hw1</B> <B>dec-base64</B> [file]</PRE>

Square bracketed items are optional.
You must follow the UNIX convention that commandline options
can come in any order, if applicable.
If <TT>file</TT> is not specified, your program should
read from <TT>stdin</TT>.
<TT>File</TT> or <TT>stdin</TT> will be referred as <I>input</I> below.
Output of your program must go to <TT>stdout</TT> and
error messages must go to <TT>stderr</TT>.

<P>

The meaning of the commands are:

<BLOCKQUOTE>
    <TABLE BORDER=0 CELLPADDING=0 CELLSPACING=0>
    <TR><TD ALIGN=RIGHT VALIGN=TOP><B>hexdump</B></TD>
        <TD VALIGN=TOP>&nbsp;&nbsp;:&nbsp;&nbsp;</TD>
        <TD VALIGN=TOP>Produce a hexdump of <B><TT>file</TT></B>
            (or <TT>stdin</TT>).
        </TD>
    </TR>
    <TR><TD ALIGN=RIGHT VALIGN=TOP><B>enc-base64</B></TD>
        <TD VALIGN=TOP>&nbsp;&nbsp;:&nbsp;&nbsp;</TD>
        <TD VALIGN=TOP><A HREF="../base64.html">
            Base64</A> encode <B><TT>file</TT></B> (or <TT>stdin</TT>).
        </TD>
    </TR>
    <TR><TD ALIGN=RIGHT VALIGN=TOP><B>dec-base64</B></TD>
        <TD VALIGN=TOP>&nbsp;&nbsp;:&nbsp;&nbsp;</TD>
        <TD VALIGN=TOP><A HREF="../base64.html">
            Base64</A> decode <B><TT>file</TT></B> (or <TT>stdin</TT>).
        </TD>
    </TR>
    </TABLE>
</BLOCKQUOTE>

<P>

The output for various commands are as follows.

<BLOCKQUOTE>
    <TABLE BORDER=0 CELLPADDING=0 CELLSPACING=0>
    <TR><TD ALIGN=RIGHT VALIGN=TOP><B>hexdump</B></TD>
        <TD VALIGN=TOP>&nbsp;&nbsp;:&nbsp;&nbsp;</TD>
        <TD VALIGN=TOP>Each line in the output corresponds
            to 16 bytes of the input file.  Here are a couple
            of examples.
            <UL>
            <LI><A HREF="usctommy.gif">sample binary file</A>
                (right-click on this link to save the file, you should
                get a GIF file 1,689 bytes in size) and
                <A HREF="usctommy.hex.txt">its corresponding hexdump output</A>
            <LI><A HREF="yesterday.txt">sample text file</A> and
                <A HREF="yesterday.hex.txt">its corresponding hexdump output</A>
            </UL>
            Please note that there is <I>one</I> space character
            between the address field and the first data byte.
            In outputing the first 8 data bytes, you must use
            <I>one</I> space character to separate each byte.
            This is followed by <I>two</I> space characters.
            In outputing the next 8 data bytes, you must again use
            <I>one</I> space character to separate each byte.
            Then follow it by <I>two</I> space characters and
            16 ASCII characters (one for each data byte).
            The rules for the last 16 characters in a line is as
            follows.
            <P>
            If the data byte is <TT>&gt;=0x20</TT> and <TT>&lt;=0x7e</TT>
            you should use the corresponding ASCII character.
            If the data byte is <TT>&lt;=0x1f</TT> or equals to
            <TT>0x7f</TT>, you should print a period character.
            If the data byte is <TT>&gt;=0x80</TT>
            you should print a ~ character.
            <P>
            In addition, non-existant bytes (at the end of the
            file) should by displayed as <TT>--</TT> and use
            space characters in the right column.
        </TD>
    </TR>
    <TR><TD>&nbsp;</TD></TR>
    <TR><TD ALIGN=RIGHT VALIGN=TOP><B>enc-base64</B></TD>
        <TD VALIGN=TOP>&nbsp;&nbsp;:&nbsp;&nbsp;</TD>
        <TD VALIGN=TOP>You should compare your result
            against the result of running the following at
            a command prompt:
            <PRE>
    <B>openssl enc -e -base64 -in</B> file</PRE>
            Please note that each line in the output must have
            at most 64 characters.  In addition, all output lines,
            except for the last one, must contain exactly 64 characters
            (plus a '\n' at the end).
        </TD>
    </TR>
    <TR><TD>&nbsp;</TD></TR>
    <TR><TD ALIGN=RIGHT VALIGN=TOP><B>dec-base64</B></TD>
        <TD VALIGN=TOP>&nbsp;&nbsp;:&nbsp;&nbsp;</TD>
        <TD VALIGN=TOP>You should compare your result
            against the result of running the following at
            a command prompt:
            <PRE>
    <B>openssl enc -d -base64 -in</B> file</PRE>
            Please note that you should ignore linebreaks in the
            input file.  Even if the input is one character per line,
            your program should still work.  Please also note that
            if the input file is garbage, your code must not crash!
        </TD>
    </TR>
    </TR>
    </TABLE>
</BLOCKQUOTE>

Pleaes output reasonable and useful error messages if the command
is malformed or file does not exist or inaccessible.
(You should do better than <TT>openssl</TT>.)

<P>

To use <TT>openssl</TT> on <TT>nunki.usc.edu</TT>, please
see the <A HREF="../../openssl.html">additional notes on <TT>openssl</TT></A>.
But please make sure that your submission
contains no reference to <TT>openssl</TT>.
            </TD>
        </TR>
        <TR><TD>&nbsp;</TD></TR>
        <!-- Section -->
        <TR><TD COLSPAN=3 ALIGN=LEFT BGCOLOR="#000000" WIDTH=100%>
                <FONT COLOR="#ffffff"><A
                NAME="grading"><B>Grading Guidelines</B></A>
                    </FONT>
            </TD>
        </TR>
        <!-- Top Section -->
        <TR><TD COLSPAN=3 ALIGN=LEFT>
<!--
The grading guidelines are not available yet.
  -->

The <A HREF="hw1-grading.txt">grading guidelines</A> has been made available.
Please run the scripts in the guidelines on <TT>nunki.usc.edu</TT>.

<P>

The grading guidelines is the <B>only</B> grading procedure we will use to
grade your program.  No other grading procedure will be used.
To the best of our effort, we will only change the testing data for
grading but not the commands.  (We may make minor changes if we discover
bugs in the script or things that we forgot to test.)  It is strongly
recommended that you run your code through the scripts in the grading guidelines.
            </TD>
        </TR>
        <TR><TD>&nbsp;</TD></TR>
        <!-- Section -->
        <TR><TD COLSPAN=3 ALIGN=LEFT BGCOLOR="#000000" WIDTH=100%>
                <FONT COLOR="#ffffff"><A
                NAME="misc"><B>Miscellaneous Requirements and Hints</B></A>
                    </FONT>
            </TD>
        </TR>
        <!-- Top Section -->
        <TR><TD COLSPAN=3 ALIGN=LEFT>
<UL>
<LI>Please read the <A HREF="../../misc/prog-faq">programming FAQ</A> if you
    need a refresher on C/C++ file I/O and bit/byte manipulications.
<P>
<LI>You must <B>not</B> use any external hexdump or base64 encoding/decoding
    libraries (such as OpenSSL) to implement this assignment.
    You must implement all these functionalities from scratch.
<P>
<LI>If the size of the input file is large, you <B>must not</B> read the
    whole file into a large memory buffer and then process the file data.
    The <B>maximum size</B> of a memory buffer is limited to
    <B>1,024 bytes</B>.
<P>
<LI>It's important that <B>every byte</B> of your data is read and written
    correctly.  You will <B>lose a lot of points</B> if one byte of data is
    generated incorrectly!  The grading of this assignment will be <B>harsh</B>.
<P>
<LI>Please follow the UNIX convention that, when your output is an ASCII
    file (such as the output of the <TT>hexdump</TT> and <TT>enc-base64</TT>
    commands), append '\n' in the last line of the output if it's not a
    blank line.  (This way, you don't get the commandline prompt appearing at
    the wrong place on the screen.)
<P>
<LI>String I/O functions such as <TT>fgets()</TT>, <TT>scanf()</TT>, and
    <TT>printf()</TT> are really meant for inputing/outputing
    null-terminated <I>strings</I>.
    Do <B>not</B> use them to input/output binary data!
<P>
<LI>The Solaris workstations in the ISD lab in SAL have the same
    setup as nunki.usc.edu.  So, if you are logged on to one of
    these workstations, please do your development locally and
    not to overload nunki unnecessarily.
<P>
<LI>Start working on this <B>early</B>!  Please don't complain
    to the instructor that this assignment is too tedious or
    it takes too much work just to parse the commandline.
    Get it done early and get it done right!
<P>
<LI>If you are interested in learning more about OpenSSL, there is
    a lot of information on the
    <A HREF="http://www.openssl.org/docs/">OpenSSL documentation site</A>.
    Please do not ask the TA or the instructor what these functions
    do and where to put them.
    Read the documentation and man pages.  Search the web.
    Try things out!  (If you are really stuck after you have
    tried quite a few different things, then you may seek help from the
    TA or the instructor.)
</UL>
            </TD>
        </TR>
        <TR><TD>&nbsp;</TD></TR>
        <!-- Section -->
        <TR><TD COLSPAN=3 ALIGN=LEFT BGCOLOR="#000000" WIDTH=100%>
                <FONT COLOR="#ffffff"><A NAME="submit"><B>Submission</B></A></FONT>
            </TD>
        </TR>
        <!-- Top Section -->
        <TR><TD COLSPAN=3 ALIGN=LEFT>
All assignments are to be submitted electronically - including
your README file. To submit your work, you must first
<TT>tar</TT> all the files you want to submit into a <B>tarball</B> and
<TT>gzip</TT> it to create a <B>gzipped tarfile</B> named
<TT><B>hw1.tar.gz</B></TT>.  Then you upload
<TT><B>hw1.tar.gz</B></TT> to the
<A HREF="../../bsubmit.html">Bistro</A> system.
On <TT>nunki.usc.edu</TT> or <TT>aludra.usc.edu</TT>,
the command you can use to create a gzipped tarfile is:

    <PRE>
    /usr/usc/bin/gtar cvzf hw1.tar.gz MYFILES</PRE>

Where <B><TT>MYFILES</TT></B> is the list of file names that you are submitting
(you can also use wildcard characters if you are sure that it will pick up only
the right files).
<B>DO NOT</B> submit your compiled code, just your source code and
README file.  <B>Two point will be deducted</B> if you submit extra
binary files, such as <TT>hw1</TT>, <TT>.o</TT>,
<TT>core</TT>, or files that can be <B>generated</B> from the rest of your submission.

<P>
Please note that the 2nd commandline argument of the <TT>gtar</TT> command above
is the <B>output</B> filename of the <TT>gtar</TT> command.  So, if you omit
<TT>hw1.tar.gz</TT> above, you may accidentally replace one of your files with
the output of the <TT>gtar</TT> command.  So, please make sure that the
first commandline argument is <TT><B>cvzf</B></TT> and the 2nd commandline argument
is <TT><B>hw1.tar.gz</B></TT>.

<P>
In your README file, you should include the command that the grader
should use to compile your code to generate <B><TT>hw1</TT></B>.
If you don't include such instruction, the grader will assume that the command
specified in the spec should be used to compile your code.
But if they can't get your code to compile easily and you don't submit
compilation instructions, you will lose points.  Please also note that
you MUST include a README file in your submission.  If you have nothing
to put inside the README file, please write "(This file intentionally left blank.)"
in your README file.

<P>
Here are a couple of sample commands for creating your <TT>hw1.tar.gz</TT> file
(your command will vary depending on what files you want to submit):
    <PRE>
    /usr/usc/bin/gtar cvzf hw1.tar.gz *.c *.h Makefile README
    /usr/usc/bin/gtar cvzf hw1.tar.gz *.cpp *.h Makefile README.txt</PRE>

You should read the output of the above commands carefully to make sure
that <TT>hw1.tar.gz</TT> is created properly.
If you don't understand the output of the above commands, you need to learn
how to read it!  It's your responsibility to ensure that
<TT>hw1.tar.gz</TT> is created properly.

<P>
You need to run <A HREF="../../bsubmit.html"><B><TT>bsubmit</TT></B></A> to
submit hw1.tar.gz to the submission server.
Please use the following command:
    <PRE><B>
    ~csci551b/bin/bsubmit upload \
        -email `whoami`@usc.edu \
        -event merlot.usc.edu_80_1372906710_62 \
        -file hw1.tar.gz</B></PRE>

Please note that the quotation marks surrounding <TT>whoami</TT> are
<B>back-quote</B> characters and not single quotes.  It's best if
you just copy and paste the above command into your console and not
try to type the whole command in.

<P>

If the command is executed successfully, the output should look like the
<A HREF="../../bsubmit.html#normal">sample mentioned in the submission web page</A>.
If it doesn't look like that, please fix your command and rerun it until it looks
right.  If there are problems, please contact the instructor.

<P>
It is extreme important that you also <A HREF="../../submit.html#verify"><B>verify your submission</B></A>
after you have submitted <TT>hw1.tar.gz</TT> electronically to make
sure that everything you have submitted is everything you wanted us to grade.

<P>
Finally, please be familiar with the <A HREF="../../submit.html">Electronic Submission Guidelines</A>
and information on the <A HREF="../../bsubmit.html">bsubmit web page</A>.
            </TD>
        </TR>
        <TR><TD>&nbsp;</TD></TR>
        </TABLE>
    </TD>
</TR>
</TABLE>

<HR>
[<I>Last updated Sun Jan 04 2015</I>] &nbsp;&nbsp;
[<I>Please see <A
HREF="../../copyright.html">copyright</A> regarding copying.</I>]

<!-- @(#)$Id: index.html,v 1.1 2015/01/04 19:36:04 william Exp $ -->

</BODY>
</HTML>

