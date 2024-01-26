# NitroCppTest-SvetlanaMorenova

Nitro C++ Proficiency Test

#Task description

Create a console program in C++ that will take a command line argument identifying a JSON file. This
file will contain rectangle definitions. Some of these rectangles may intersect with one or more others.
The objective is to report on the set of those intersections.
For example, the rectangles on the left result in the intersections on the right.
![image](https://github.com/Morenova/NitroCppTest-SvetlanaMorenova/assets/11922964/132b10c8-9c17-4fdd-aa23-aab50673f0a5)


Each of the lightly shaded areas is the intersection between two rectangles. Each of the darkly shaded
areas is an intersection between three rectangles.
The JSON file defines a collection of rectangles in a 2D space
using X, Y integer coordinates for one corner and a width and
height value. Width and height are integers that are never
negative. Rectangles have X,Y at the top left corner.
![image](https://github.com/Morenova/NitroCppTest-SvetlanaMorenova/assets/11922964/ee69853e-f51d-4d27-a3dd-b5a80e7b41e2)


On start-up, the JSON file will be loaded and validated. Then two lists will
be outputted: the list of all rectangles in the input file; and the list of all intersections.
There are a few points to bear in mind:
• The JSON file may contain any number of input rectangles. Your program must be able
to process JSON files containing at least 10 rectangles. You may discard the remaining
rectangles after the first 10.
• Multiple input rectangles with the same coordinates and sizes are nevertheless distinct.
All should be included when determining intersections.
• Rectangle AÇB is the same as BÇA and should result in only one rectangle in the result.
Take care not to accidentally include both.
• With the exception of AÇB and BÇA above, duplicate matching intersections should be
included in the result. Despite being the same, they are distinct intersections.
• The result must include all intersections involving two or more rectangles.

#Input:

Json file with following format:

![image](https://github.com/Morenova/NitroCppTest-SvetlanaMorenova/assets/11922964/8fb9dca7-b31b-46f6-a09e-663e32b91d83)


#Output:

Programm output in following format:

![image](https://github.com/Morenova/NitroCppTest-SvetlanaMorenova/assets/11922964/724420e0-8dbb-4af6-8291-2edfc6a9e183)


#Build instructions

The project is configued to get and build all external dependencies automatically.
External dependencies are:

Google Test - Google's C++ test framework.

Nlohmann - A C++ library for interacting with JSON. 

Microsoft Visual Studio 2022 C++ Compliler

Building instuction:
1. Open MS Visual Studio solution Rect_intersection\Rect_intersection.sln
2. Build Solution

Test:
1. Open Open MS Visual Studio solution Rect_intersection\Rect_intersection.sln
2. Select RectTest solution
3. Right button click - Set us Startup project
4. Build Solution


