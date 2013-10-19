1. Starting a project
=====================

We presume you use git to version manage your project. If not some commands need to be changed.

Yaal contains script for helping you out when you start a new project or want to use YAAL in your current project. In any case, lets start.

First. Project directory. If you have one allready, skip this.

```sh
mkdir my_project_path
cd my_project_path
git init .
```

Lets add YAAL as git submodule.

```sh
git submodule add https://github.com/raphendyr/yaal.git vendor/yaal
```

Or if you do not have git repository for your project, use:

```sh
git clone https://github.com/raphendyr/yaal.git vendor/yaal
```

Now we have YAAL in `vendor/yaal` directory. This path doesn't matter very much as YAAL makefile will take care of includes and stuff like that. Only places where this path is are following init script and makefile created by it. So if you want to change it after wards, you need to edit makefile.

Initialize your project (Creates `Makefile` and `main.cpp` for starting point).

```sh
./vendor/yaal/init_project.sh
```

Now your project is set up to use YAAL. For last thing, you should commit these changes.

```sh
git commit -m "Project initialization"
```

You should now edit `Makefile` to match your project and start coding into `main.cpp`.

Next is the [basics](2_basics.md).
