A -> steps to create an virtual environment: 
  1: navigate to project 
  2: python -m venv custome_env  
  3: activate the environment as
      source ~/file_location/custome_env/bin/activate
  4: check the pip list 
  4.5: then use below command to install a kernel
      pip install ipykernel

      below command is optional check if kernel is present or not it is stored in ~/.local/share/jupyter/kernels/custome_env/
      python -m ipykernel install --user --name=custome_env --display-name "Python (myenv)"
  5: install the necessary depencencies : 
      pip install numpy pandas matplotlib seaborn scikit-learn
  6: to open jupyter notebook use : jupyter notebook
  7: if 6 show error use command : pip install notebook > jupyter notebook
  8: (optional) if jupyterlab is required then :  
    pip install jupyterlab
    jupyter lab

  9: deactivate


B -> If we did a project and now we wanna push it to github then use following command: 
  1: pip freez > requirements.tsx
  2: ls -> requirements.txt file will be shown

C -> Accessing the requirements.txt file
  1: python -m venv new_env
  2: source ~/file_location/new_env/bin/activate
  3: ls -> requirements.txt file should be there
  4: pip install -r requirements.txt
  5: pip list (installed all files)

D -> Best practice is that create a new folder named as venv in root of our project and make an virtual environment in this venv file rather that on root project file 

E -> PURPOSE OF VENV : 
    A Python environment is an isolated workspace where specific versions of Python and its libraries are installed. It allows you to:
    Keep your ML project dependencies separate.
    Avoid conflicts between different libraries.
    Work on multiple projects with different versions of the same library.

F -> Anaconda : it works similar as pip 
  ❓ Do Anaconda and pip do the same job?
  Yes, kind of... but with differences.
    | Tool         | What it does                                                                 |
    | ------------ | ---------------------------------------------------------------------------- |
    | **pip**      | Installs Python packages from PyPI                                           |
    | **Anaconda** | A full data science platform with its own package manager (`conda`) + extras |


