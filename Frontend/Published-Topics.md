What is HTML?

1. HTML stands for Hyper Text Markup Language
2. HTML is the standard markup language for creating Web pages
3. HTML describes the structure of a Web page
4. HTML consists of a series of elements
5. HTML elements tell the browser how to display the content
6. HTML elements label pieces of content such as "this is a heading", "this is a paragraph", "this is a link", etc.

Example:
 
<!DOCTYPE html> 
<html>
<head>
<title>Title</title>
</head>
<body>

<h1>Digital Ocean</h1>
<p>Hacktoberfest-2020</p>

</body>
</html> 

<!------------------------------------------------------------------------------------------------------>

What is CSS?

1. CSS stands for Cascading Style Sheets
2. CSS describes how HTML elements are to be displayed on screen, paper, or in other media
3. CSS saves a lot of work. It can control the layout of multiple web pages all at once
4. External stylesheets are stored in CSS files

Example:

body {
  background-color: lightblue;
}

h1 {
  color: white;
  text-align: center;
}

p {
  font-family: verdana;
  font-size: 20px;
}

<!--------------------------------------------------------------------------------------------------------->


JavaScript

1. JavaScript Can Change HTML Content
One of many JavaScript HTML methods is getElementById().

Example below "finds" an HTML element (with id="demo"), and changes the element content (innerHTML) to "Hello JavaScript":

document.getElementById("demo").innerHTML = "Hello JavaScript";

2. JavaScript Can Change HTML Styles (CSS)
Changing the style of an HTML element, is a variant of changing an HTML attribute:

Example
document.getElementById("demo").style.fontSize = "35px";

3. JavaScript Can Show HTML Elements
Showing hidden HTML elements can also be done by changing the display style:

Example
document.getElementById("demo").style.display = "block";


