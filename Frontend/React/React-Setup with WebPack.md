# ReactJs and Webpack setup from SCRATCH

Setting up React & Webpack from scratch!!

> In this article, we will understand How we can set up [REACT](https://reactjs.org/docs/getting-started.html) with [WEBPACK](https://webpack.js.org/) rather than using **CRA.**
> I assume we have a basic understanding of what webpack is and of course ReactJs.

If you’re in a rush, you can directly dive into the [source code](https://github.com/himesh-dev/react_webpack_scratch) and follow it commit by commit.

> # Let’s Begin! If you can code along it will be great.

1. Make a directory/folder and go inside the folder. (I will use my terminal to make a directory)

   mkdir <FOLDER_NAME> && cd <FOLDER_NAME>

2. In the terminal we will write (Open your terminal if you haven’t).

![package.json](https://cdn-images-1.medium.com/max/2000/1*hs43K9Lsu3BFYgP-XpVCbA.png)_package.json_

    npm init -y

It will create a **_package.json_** in our project folder.

(like this)

3.  Now we will install Webpack dependencies as dev-dependencies.

    npm install webpack webpack-cli webpack-dev-server --save-dev

4.  We will now install babel dependencies also as dev-dependencies.

        npm install @babel/core babel-loader @babel/preset-env @babel/preset-react --save-dev

    > # What does these dependencies do?

- [**webpack**](https://webpack.js.org/concepts/): webpack is a module bundler. Its main purpose is to bundle JavaScript files for usage in a browser, yet it is also capable of transforming, bundling, or packaging just about any resource or asset.

- [**webpack-cli**](https://webpack.js.org/guides/getting-started/): If we are using webpack v4 or later it is required to be installed.

- [**webpack-dev-server**](https://www.npmjs.com/package/webpack-dev-server): Use webpack with a development server that provides live reloading. This should be used for development only.

- **@babel/core**: It’s a JavaScript transpiler to converts modern JavaScript into a production-ready version that’s compatible with all browsers.

- **babel-loader**: This package allows transpiling JavaScript files using Babel and webpack.

- **@babel/preset-env**: It is a smart preset that allows you to use the latest JavaScript without needing to micromanage which syntax transforms are needed by your target environment.

- **@babel/preset-react**: It is a React specific plugin which converts JSX into plain JavaScript.

**NOTE:** We are using `--save-dev` flag to keep our development-specific dependencies separate and not to include in the production bundle.

5. Now let’s create webpack config file i.e., webpack.config.js in the root directory (as the same level as package.json).

   `touch webpack.config.js`

6. Let’s open our favourite code editor (mine is VScode). In webpack.config.js add the below code.

```
  const path = require("path");

    module.exports = {
       entry: "./index.js",
       output: {
          path: path.resolve(__dirname, "build"),
          filename: "bundle.js",
       },
    };
```

- Here we have imported/ required path to get the path of the immediate folder.

- Then we will export this module (it will have various options we will learn more later in the article)

- **entry** is the entry point for the project (we will create index.js later), & in **output,** the path is the path of the optimized build (production-ready)code bundle and filename is the name of the output bundle file.

7. Now we will add a **module** which will have an array of rules which is used to process the files depending upon the test it matches and uses loaders to process them.

```
    module.exports={

    //previous code from above steps

    module: {
      rules: [
        {
          test: /\.(js|jsx)$/,
          exclude: /node_modules/,
          use: {
            loader: "babel-loader",
            options: {
               presets: ["@babel/preset-env", "@babel/preset-react"],
            },
          },
        },
      ],
    },
    }
```

8. Now let’s add a **plugin** in the webpack config file. We will add [html-webpack-plugin](https://webpack.js.org/plugins/html-webpack-plugin/#root) . This plugin will generate an HTML5 file for you that includes all your webpack bundles in the body using script tags. But first we need to install it and import it in webpack.config.js.
```
   //in the terminal
   npm install --save-dev html-webpack-plugin

   //webpack.config.js
   //import HtmlWebpackPlugin

   const HtmlWebpackPlugin = require("html-webpack-plugin");

   //we will add following code after the module option.

   module.exports = {
   //previous codes, entry, output, modules

   plugins: [
   new HtmlWebpackPlugin({ template: "./public/index.html"})
   ],
   }
```
(we will create index.html inside public folder later).

9. Now we will create a .[babelrc](https://github.com/himesh-dev/react_webpack_scratch/blob/master/.babelrc) in the root directory and add following code inside that file.
```
   // in terminal
   touch .babelrc

   // in .babelrc file

   {
   "presets": ["@babel/preset-env", "@babel/preset-react"]
   }
```
10. Let’s create a public,index.js in the root directory of the project.
```
mkdir public && touch index.js
```
and **index.html** inside thepublic folder.

    cd public && touch index.html

Now open index.html in Code editor and add the basic HTML code and create a div with id as root, where we will inject all our React code.

    //  ./public/index.html

    <!DOCTYPE html>
      <html lang="en">
        <head>
          <meta charset="UTF-8" />
          <meta name="viewport" content="width=device-width, initial-scale=1.0" />
          <title>React Webpack Scratch</title>
        </head>
        <body>
          <div id="root"></div>
        </body>
      </html>

11. Let’s install **React** & **ReactDom** but as dependencies not as dev-dependencies.
```
    // in terminal
    npm install --save react react-dom

    //react & react-dom will be now available inside dependecies key in //package.json
```
12. Now we will add scripts inside the scripts key in **package.json** for starting and running the project and for making a build.
```
    //package.json

    "scripts":{
    "start": "webpack-dev-server --open",
    "build": "webpack",
    }
```
- on running npm start will start the development server using `webpack-dev-server` and `--open` will open the localhost in the browser.

- on running npm buildwill create a javascript bundle file in the output directory as mentioned in the webpack.config.js file.

13. If you remember we have created index.js on step no. 10 . We will add some code in index.js .
```
    _import_ React _from_ "react";
    _import_ ReactDOM _from_ "react-dom";

    ReactDOM.render(\<h1>hello\</h1>, document.getElementById("root"));
```
14. Now let’s start the server by running npm start in the terminal.

    > # Hurray! we successfully configured webpack.

15. Let's create a src folder where we will keep overall codes.
```
    mkdir src && cd src && touch App.js
```
Don’t forget to import App.js in the index.js .

    // index.js
    import React from "react";
    import ReactDOM from "react-dom";
    import App from "./src/App";

    ReactDOM.render(<App />, document.getElementById("root"));

    //add code inside App.js
    import React from "react";

    const App = () => {
        return (
           <div className="App">
             <h1>Hello</h1>
           </div>
        );
    };
    export default App;

16. If you try creating a .css file and import it in js file it give this error.

![importing CSS error](https://cdn-images-1.medium.com/max/3540/1*jzO-n94DmBP8eM5_zofb7g.png)_importing CSS error_

To fix this issue we need to install style-loader & css-loader as dev-dependencies to process style or CSS files and also need to add rules in the module section of webpack.config.js fille.

    // in terminal
    npm install --save-dev style-loader css-loader

    // in webpack.config.js inside rules array add below code

    rules:[
    ...previous rules,
    {
      test: /\.css$/,
       use: ["style-loader",
             {
                loader: "css-loader",
                options: {
                  modules: {
                    auto: true,
                    localIdentName: "[name]__[local]__[hash:base64:5]",
                  },
               },
            },
         ],
      },
    ]

Now restart the server using npm start .

> # Yayy! now we can style our app.

But there is one more **issue**, we still cannot use **images** in our project.

I will recommend to attempt it yourself.😀

**Hint:** You will need [file-loader](https://webpack.js.org/loaders/file-loader/#root) for this.

> Final [webpack.config.js](https://github.com/himesh-dev/react_webpack_scratch/blob/master/webpack.config.js)



> Final [package.json](https://github.com/himesh-dev/react_webpack_scratch/blob/master/package.json)



Thanks for reading.

If you like it or have found it useful, can I get a round of applause?👏🏻👏🏻👏🏻👏🏻
