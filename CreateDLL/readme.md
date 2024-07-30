## Creating a DLL & using it
to compile the DLL : g++ -shared -o MyDLL.dll MyDLL.cpp
to generate exe : g++ -o MyApp main.cpp -L. -lMyDLL 
