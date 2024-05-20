#CS-361 Communication Contract

Git clone in git bash using the page link or directly download the files locally from this page.

REQUEST

For requesting data, you need to simply have a feature that allows you to write into a .txt file (which specifically is named "start.txt").
You can obviously change the .txt file to one that you prefer. However, there is no need to. 

The main.cpp file is a very simple program that imitates a possible main program. You will have to somehow use similar logic to write the keyword to the 
"start.txt" file. 

Here are some ways if you have Javascript or Python:

    Javascript: 
        const fs = require('fs');
        fs.appendFile('start.txt', 'run\n', (err) => {
        if (err) {
            console.error('Error: Unable to open file start.txt for appending.');
        } else {
            console.log('The word "run" was successfully appended to start.txt.');
        }
        });

    Here, the 'fs' module allows you to use appendFile in order to append to "start.txt" and throw and error in case "start.txt" does not exist.
    In your main program, this is all you have to do in order to get it working for JavaScript.

    Python: 
        try:
            with open('start.txt', 'a') as file:
                file.write('run\n')  # Append the word "run" followed by a newline
            print('The word "run" was successfully appended to start.txt.')
        except IOError:
            print('Error: Unable to open file start.txt for appending.')

    In Python, there is a context manager, which is nice to be familiar with. The 'a' opens "start.txt" for append mode. 
    Then, file.write helps to write the word "run" into the text file, and that is all that happens.

And in case there is any confusion despite using C++ for your main program, here is this:

    C++: 
        ofstream outputfile("start.txt", ios::app);
        if (outputfile.is_open()) {
            outputfile << "run" << endl; //Append the word "run" followed by a newline
            outputfile.close();
        } 
        else
            cerr << "Error: Unable to open file start.txt for appending." << endl;
        
    This program is using the <fstream> library to output the keyword "run" using the ios::app (known as append) in the library. 
    It also does error handling for you in case the file you are outputting to is not an actual file or is in a separate directory.

As for the word "run" always staying in the file, you do not have to worry about it since it will not trigger again as the word "run" is removed 
from "start.txt" after it is detected. 

To request and receive properly, one downside is that you will likely need another terminal open to run the program separately, unless you already
have your program implemented in C++, which this microservice was based off of. 

RECEIVE

Run these lines to have the microservice program actively running and looking for the keyword "run" in the text file used for this microservice:
    
    g++ recipes.cpp
    ./a.out

    Take into consideration that ./a.out may differ based on what machine you are using. For example, the server you are on or possibly even
    the editor may cause a difference.

    The microservice will automatically do all the work for you and place a random recipe in "start.txt" based on your choice. Then, the main program
    will read it and display it on the terminal.

UML Sequence Diagram

![image](https://github.com/DanKLee0103/CS-361/assets/161083419/83418dff-aeca-4498-b289-1785a397fd76)


