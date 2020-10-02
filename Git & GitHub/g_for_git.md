---
title: Git for Beginners
description: Git and it's work
tags: git, version-control, git-basics
cover_image: https://thepracticaldev.s3.amazonaws.com/i/okwwuj6j6pwruiu5wew8.png
---


## What is git?

Git is a distributed version control system which helps developers to collaborate globally.

## Why we need such version control system?

Well we need version control system for the following reasons:-
- It keeps the history of changes developers made.
- We know who made what changes.
- It merges conflicting changes (such as two people modified a single file at the same time then it will merge both the changes).

## Workflow that makes you project flow smoothly

There are 3 workflows that you can go within Github, namely:-
- Centralized Workflow
  > It is used generally for small teams where everyone works on single branch in a central repository

- Feature Branch Workflow
  > Features developed in dedicated branches and then merged with the main codebase using pull request. Here the main codebase is kept clean and working

- Forking Workflow
  > Each developer forks from the main repo and do changes and send pull requests. Here each developer will have own online repo of the project

Since this a small project right now I will start with centralized workflow.


## Enough theory let's do some practical

As hasura provides git integration in their platform I am going to use GitHub as my code repository. So let's initialise our codebase. For instructions about installing git on your computer go to [this link](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git). First I have to create a folder and type the command

`git init`

This will initialise my codebase and track my changes. You will see a hidden folder is created inside my folder snipcode named **.git**. It contains all the files required for version control. 

![](https://thepracticaldev.s3.amazonaws.com/i/gmv5tsol49qhnxkjf5q6.png)

After adding a readme file to commit the following changes in snip code we have to add and it to the staging area and then commit.

![](https://thepracticaldev.s3.amazonaws.com/i/k9xeci60zygpagirwi4a.png)

`git add README.md`
`git commit -m "Initial commit"`

![](https://thepracticaldev.s3.amazonaws.com/i/47ksqza3o99h5drq51kx.png)

git commit has an option of adding a message to the commit.

Now all these are happening in my local environment. To push my codebase in GitHub I have to create a repo named snipcode.

![](https://thepracticaldev.s3.amazonaws.com/i/vgry0lysq9phkkuec9qn.png)

After this, I will add the remote in my local repo with name origin(general convention).

`git remote add origin https://github.com/sroy8091/snipcode.git`

Finally, I will push my local repo to GitHub using push command in the master branch

`git push origin master`

![](https://thepracticaldev.s3.amazonaws.com/i/5pjpu4qd2vro7p39m4fz.png)

One of the useful commands is **_git status_**. We should always use this to know the status of working tree. One snapshot of my project's status is

![](https://thepracticaldev.s3.amazonaws.com/i/w9y8p0aitupptgde6brm.png)

And here is the cheat sheet for git provided by the Tower.

![](https://thepracticaldev.s3.amazonaws.com/i/4wd1073qq4gk3nf4luvz.png)


> This work is originally posted [here](https://dev.to/sroy8091/g-for-git)  by me and is a part of series