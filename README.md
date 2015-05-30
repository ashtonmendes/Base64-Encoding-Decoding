
<HTML>
<HEAD>
<TITLE>Homework #1 - CSCI 531, Spring 2015</TITLE>
<LINK HREF="../../cs531bc.css" REL="stylesheet" TYPE="text/css">
<LINK REV="made" HREF="mailto:bill.cheng@acm.org"></HEAD>
<BODY BGCOLOR="#FFFFFF" LINK="#D02090" VLINK="#996600" ALINK="#990000">

<TABLE BORDER=0 CELLPADDING=0 CELLSPACING=0 WIDTH=100%>
<TR>
    
    <TD ALIGN=LEFT VALIGN=TOP>
    <!-- COL 3, every page should be different -->
        <TABLE BORDER=0>
        <!-- Page Header -->
        
        
        <TR><TD>&nbsp;</TD></TR>
        <!-- Section -->
        <TR><TD COLSPAN=3 ALIGN=LEFT BGCOLOR="#000000" WIDTH=100%>
                <FONT COLOR="#ffffff"><A
                NAME="intro"><B>Assignment</B></A></FONT>
            </TD>
        </TR>
        <!-- Top Section -->
        <TR><TD COLSPAN=3 ALIGN=LEFT>
The purpose of this assignment is to get acquainted
with manipulating bits in memory and files.

<P>
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
    <PRE>
    make hw1</PRE>
an executable named <B>hw1</B> is created.
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
Follows the UNIX convention that commandline options
can come in any order, if applicable.
If <TT>file</TT> is not specified, the program
reads from <TT>stdin</TT>.
<TT>File</TT> or <TT>stdin</TT> will be referred as <I>input</I> below.
Output of the program goes to <TT>stdout</TT> and
error messages go to <TT>stderr</TT>.

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
        <TD VALIGN=TOP>
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

<P>

</TD>
</TR>


</BODY>
</HTML>

