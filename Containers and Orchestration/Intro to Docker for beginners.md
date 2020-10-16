# What are Containers? An introduction to dockers for beginners.
*In this small article, you are going to get the gist of container concepts and an introduction to docker. At the end there are some resources provided apart from this article which I think can help any beginner get started working with docker and containers.*
## Article Outline:
Here is the list of concepts (some questions that you get your answers for!) you can learn about after reading this article.
- [Well, what are containers?](#Containers)
- [What is docker?](#Docker)
- [Why docker when there is VM already?](#How-is-Docker-better-than-VM)
- [Why does a developer need to learn about docker or any containerization tool?](#A-developers-need-to-learn-about-Docker-and-containers)
- [Basic docker commands](#Basic-docker-commands)
- [Resources: What next?, installation steps, glossary, cheat sheet etc.](#Resources-and-Next-Steps)

So, lets get started :)

## Containers

When an application is written, it more oftenly uses libraries, packages and other forms of third party code as dependencies which support the application being written to work. Generally while deploying your apps or sharing it with end users, these dependencies are kept apart and are just mentioned in a metadata file for the application. (eg. package.json for JavaScript projects, pom.xml file for java maven projects etc.) This is mostly an optimal approach because you need not deal with the overhead of the size of those extra files and even the time it takes up for you to check in and for the person using it to get it.

But, like most things, this has its downsides too. Mainly, there are two pressing issues with this approach. Firstly, dependency versions are frequently updated by the maintainers and there is no guarantee that the user gets the same version of a dependency that you have written your application to work with(There are ways for listing the dependencies to make sure your user gets the same versions of it. But then another issue comes up which I’ll point out next). Each package might work differently with different OS that the user uses and unfortunately this is not in the developers hands to choose.

Hence, to tackle these concerns, enter the hero: Container! ***Container, in simple terms, is defined as the holder that contains all the necessities for that app to run viz., source code, configurations, dependencies and sometimes even documentation and guidelines*** (But fundamentally code, configurations and dependencies). You put all these together and the application works fine without needing something external, as simple as that!

## Docker
Previous section said that a container is something that contains stuff that your app needs to run. Well, Docker is a containerization tool that helps you create(build), run and deploy them anywhere or even share your applications with other people seamlessly. Most important thing that makes docker stand out is because it saves everyone a lot of time (and as we know ***TIME IS MONEY***) and not only does it save time but it guarantees that a code running on one system, one OS and in one environment, runs everywhere (hence, there is no excuse such as ***IT WORKS JUST FINE ON MY SYSTEM*** :p). Docker deals with the issue of different systems, even different OS and environment by isolating the whole application as an independently running process. But, at this point you might have this commonly asked question: Doesn’t a Virtual Machine(VM) solve this problem? Well, you can read about that in the next section.

## How is Docker better than VM?
Though both docker and VM help users run different applications and processes in isolation and have even different OS on the same host machines, the very way of how they operate and the purposes they serve are entirely different. I am going to cover the fundamental edges that docker has over VM here. But there is [this blog post on Docker’s website](https://www.docker.com/blog/containers-replacing-virtual-machines/) that can help you go in depth if interested on how they are different and the various other concerns. This article also lets you know about how both of these consume the host OS and disk space. A couple of important observations and points that I want to make here is that Docker’s implementation is really best in such a way that it reduces the disk space that you require in comparison with that of a VM and more importantly there are ways in which you can bind and let multiple docker containers running on a single or multiple host machines which can really be instrumental while building applications that need huge number of dependent services and processes. Moreover there are concepts like container orchestration that deals with making multiple containers work in tandem, maintaining the number of containers of a particular image needed which is really hard to achieve in case of VM.

## A developer’s need to learn about Docker and containers
Currently, the use of dockers and containerization is predominantly for the deployment and management of the applications rather than the actual development of it and we know that this is taken care of by a DevOps professional. Obviously now the question arises: how does it help a developer to learn docker or any containerization tool out there? Here, I want to let you know this practice happens in most of the start-ups and very bigger organizations whose main concern is to develop fast and which deal with iterative releases. These companies do not want to waste time on people working there or people they hire newly to work their entire week to just set up code on their local system, because simply no one can afford to waste such huge amount of time which can be used in doing something productive such as an actual contribution( Because again ***TIME IS MONEY***). Hence here, again the hero, docker enters. You just turn on your workstation, be it of any OS you just set up docker and pull the image for the app you are working and in just a matter of hours, you are good to go. And not just this, when you are building apps in terms of images, their deployment and testing can be done by you, a developer seamlessly, without going to a DevOps guy and the current day cloud services like Elastic Beanstalk by AWS can help you with this purpose so easily to get the production feel of it. And moreover when a docker image works well on one system, it works really well anywhere!
## Basic docker commands
Here, I have listed the most used docker Command Line Interface(CLI) commands to start with.

1.  **docker pull:**
This command lets you pull a docker image from DockerHub (DockerHub is the official docker image repository to store and fetch all the docker images).
Usage: `docker pull <image name>`
Example: To pull an image with name ABCXYZ, you can use `docker pull ABCXYZ`

2.  **docker run:**
This is the command used to run a docker image on your host system.
Usage: `docker run <image name>` (OR) `docker run -it -d <image name>`
Example: To run an image with name ABCXYZ, you can use `docker run ABCXYZ` (OR) `docker run -it -d ABCXYZ`
> [here -it is to run an image in interactive TTY mode and -d to run in
> daemon mode]

3.  **docker build:**
This command is used to build a docker image using your source code
Usage: docker build .
> [here . is to indicate that the current folder contains your source
> code]

4.  **docker exec:**
You can use this command to access control over your running container and execute commands.
Usage: `docker exec -it <container id> bash`
Example: For a container with id 0123456789ab, you can use `docker exec -it 0123456789ab bash`

5.  docker stop:
This command is used to stop running containers
Usage: `docker stop <container id>`
Example: To stop a container with id 0123456789ab, use `docker stop 0123456789ab`

6.  docker kill:
This command is similar to stop, but the only difference is that stop does it gracefully but kill takes a forceful approach.
Usage: `docker kill <container id>`
Example: For a container with id 0123456789ab, `docker kill 0123456789ab`

7.  docker ps:
This command lists all the running containers.
Usage: `docker ps`

8.  docker images:
This command lists all the images that are available locally on host machine
Usage: `docker images`

9.  docker push:
This command is used to push the docker image you built into DockerHub.
Usage: `docker push <DockerHub username>/<image name>`
Example: If your username is ABC and you need to name your image XYZ, you can run the command as `docker push ABC/XYZ`

10.  docker rm:
This command removes a container from the host machine. (Note: In order to stop a container, it has to be stopped or killed first or a --force/-f flag has to be used)
Usage: `docker rm <container id>`
Example: For a container with id 0123456789ab, use `docker rm 0123456789ab`

11.  docker rmi:
This command is used to remove a particular image from your host machine. (Note: Similar to docker rm, this command works successfully only when no running container is using this particular image)
Usage: `docker rmi <image-id>`
Example: For an image with image id 0123456789ab, use `docker rmi 0123456789ab`
## Resources and Next Steps
-   A product’s official documentation is always a better place to start learning about it and starting to work with it. So, here is the link to Docker’s official documentation: [docs.docker.com](https://docs.docker.com/)
-   If you are interested to dive deeper into Docker and Kubernetes, there is an amazing video on FreeCodeCamp’s YouTube channel at [this link](https://www.youtube.com/watch?v=t8GbPocwQW0).
-   [Here is a cheat sheet in PDF for docker commands from their official website](https://www.docker.com/sites/default/files/d8/2019-09/docker-cheat-sheet.pdf).
-   You can find all the docker terminologies [here](https://docs.docker.com/glossary/).

Happy Exploring and Learning :) Sayonara :D
