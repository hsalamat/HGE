REM Make sure you do a recursive to get all the submodules
REM git clone --recursive https://github.com/hsalamat/HGE   
git status
git add *
git commit -m "Setup Logging and Premake"
git push origin master
REM git submodule add https://github.com/gabime/spdlog vendor/spdlog 
REM git submodule add https://github.com/glfw/glfw vendor/GLFW
