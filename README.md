# remote-config

A simple client/server application written in Qt to change configurations remotely.

## The applications

The project is organized in `Server` and `Client`. Both have their own subdirectories.

## How to run

Make sure that you have Qt installed in your machine. If you don't have it, use [its official documentation](https://www.qt.io/download) to install it.

> **Note:** The Qt version used in the development is 6.6.0

Once Qt is installed, you can use `qmake` and `make` to build the applications. Using a terminal, go to the application directory (`Client` or `Server`) and run `qmake` (to generate the Makefile) and build the application using `make`.

After the building has been finished, you can locate and run the application (binary file) in the same directory that you performed the commands. For example, in a Mac OS the `Server` application is located at:

```text
<CUR_DIR>/Server.app/Contents/MacOS/Server
```

Just go to the folder and run the application, like:

```bash
cd Server.app/Contents/MacOS/
./Server
```

Apply the same idea for the `Client` application.

### The config file

The data that is being sent from the `Client` is saved in a text file called `remote-config.txt`. This text file is located at the same directory where the `Server` is running.

You can use the command `tail` to verify the file content when it is being updated.

```bash
tail -f remote-config.txt
```
