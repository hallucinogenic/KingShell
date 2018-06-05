# KingShell

This is just a program which I made in my class, to simulate a linux Shell;

# Commands (Built-In)

<ul>
  <li><b>help</b> -> It shows a list of built-in commands on standard output;</li>
  <li><b>sair/exit/quit NUMBER</b> -> It shutdowns the program after X seconds (if you just write "quit", it will be shutdown after 3 seconds;</li>
  <li><b>cd</b> -> It changes your current directory;</li>
  <li><b>42</b> -> It shows the explanation of number 42;</li>
  <li><b>sols</b> -> Shows the list of files and folders in the current directory;</li>
  <li><b>aviso MESSAGE NUMBER</b> -> Shows an warning message after NUMBER seconds;</li>
  <li><b>avisoth MESSAGE NUMBER</b> -> Shows an warning message after NUMBER seconds (by using threads);</li>
  <li><b>PS1=NAME</b> -> It changes the default prefix to a word that you want to choose (if you write {default} it will give the default prefix;</li>
  <li><b>calc NUMBER OP NUMBER</b> -> It calculates an operation between two real numbers;</li>
  <li><b>bits NUMBER OP NUMBER</b> -> It calculates a binary operation between two integer numbers;</li>
  <li><b>quemsoueu</b> -> It calls the system("id") function;</li>
  <li><b>socp FILE1 FILE2</b> -> It copies the content of FILE1 to FILE2;</li>
  <li><b>socpth FILE1 FILE2</b> -> It copies the content of FILE1 to FILE2 (using threads);</li>
  <li><b>rocket</b> -> It shows a rocket in the standard output (see https://helloacm.com/simple-cc-rocket-animation/ )</li>
  <li><b>jpg (or jpeg) FILE1</b> -> It checks if FILE1 is a JPEG file;</li>
<ul>

# Redirects, Pipes, Background/Foreground and Threads

This program also has redirect support for non-builtin commands (e.g: <b>ls</b>), also as Pipe and Backgroud executes support;

Supported Redirects:

<ul>
  <li><b>Input</b> (<);</li>
  <li><b>Append Output</b> (>>);</li>
  <li><b>Output</b> (>);</li>
  <li><b>Error Output</b> (2>);</li>
</ul>
