## 🎯 3-Week ML Foundation Mastery Plan

# ✅ WEEK 1: ML PREREQUISITES (Python + Math + Data Handling)

| **Day** | **Topic**       | **Learning**                       | **Hands-on Practice**               |
| ------- | --------------- | ---------------------------------- | ----------------------------------- |
| Day 0   | env and anacond | installation and adding env        |
| Day 1   | Python Basics   | Variables, lists, loops, functions | Colab Notebook                      |
| Day 2   | OOP & File I/O  | Classes, reading/writing CSV       | Address Book CLI                    |
| Day 3   | NumPy           | Arrays, broadcasting               | Matrix ops                          |
| Day 4   | Pandas          | DataFrames, filtering, `groupby`   | Load Titanic/Heart dataset          |
| Day 5   | Matplotlib      | Plotting basics                    | Plot from CSV                       |
| Day 6   | Seaborn         | Heatmap, pairplot, distplot        | Titanic dataset                     |
| Day 7   | Math for ML     | Mean, Std Dev, Probability, Bayes  | Write simple calculations in Python |

# ✅ WEEK 2: DATA PREPROCESSING + CORE ML CONCEPTS (Start SKLEARN here 🔥)

| **Day** | **Topic**                    | **Scikit-learn Modules to Use**                                 | **Code Practice**                   |
| ------- | ---------------------------- | --------------------------------------------------------------- | ----------------------------------- |
| Day 8   | What is ML? + Types          | (No code yet)                                                   | Understand supervised, unsupervised |
| Day 9   | Data Cleaning + Splitting    | `train_test_split`, `SimpleImputer`                             | Load + clean + split Heart dataset  |
| Day 10  | Feature Encoding             | `LabelEncoder`, `OneHotEncoder`                                 | Encode categorical features         |
| Day 11  | Scaling & Normalization      | `StandardScaler`, `MinMaxScaler`                                | Normalize Titanic/Heart dataset     |
| Day 12  | Evaluation Metrics           | `accuracy_score`, `precision_score`, `recall_score`, `f1_score` | Confusion Matrix practice           |
| Day 13  | K-Fold CV + LOOCV            | `cross_val_score`, `KFold`, `LeaveOneOut`                       | Apply cross-validation              |
| Day 14  | Pipeline + Feature Selection | `Pipeline`, `SelectKBest`                                       | Create ML pipeline end-to-end       |

# WEEK 3: BASIC ML MODELS (Regression, Classification, Clustering)

| **Day** | **Topic**           | **What to Learn / Do**                                           | **Scikit-learn Functions**                           |
| ------- | ------------------- | ---------------------------------------------------------------- | ---------------------------------------------------- |
| Day 15  | Linear Regression   | Model, MSE, MAE, R² Score                                        | `LinearRegression`, `mean_squared_error`, `r2_score` |
| Day 16  | Logistic Regression | Binary Classification + Confusion Matrix                         | `LogisticRegression`                                 |
| Day 17  | KNN                 | K-Nearest Neighbors, Distance Metrics                            | `KNeighborsClassifier`, `KNeighborsRegressor`        |
| Day 18  | SVM                 | Linear SVM, Kernels (RBF, Polynomial)                            | `SVC`, `svm.SVC(kernel='rbf')`                       |
| Day 19  | K-Means Clustering  | Centroids, Elbow Method, Clustering real data                    | `KMeans`, `silhouette_score`                         |
| Day 20  | Model Comparison    | Compare all models built so far using one dataset                | `cross_val_score`, `GridSearchCV`                    |
| Day 21  | Final ML Project    | Select any Kaggle dataset, build full pipeline + model + metrics | Use all of the above                                 |

# Projects

🟩 Week 1: Python, Pandas, Matplotlib, Seaborn
🎯 Project 1: Exploratory Data Analysis (EDA) on Titanic Dataset
Skills: Data cleaning, visualization, feature analysis
Tools: Pandas, Matplotlib, Seaborn

📌 Tasks:
Load Titanic dataset from Kaggle
Clean missing values (Age, Cabin)
Visualize relationships (Survival vs Age/Gender/Pclass)
Feature correlation heatmap
Bar plots, Histograms, Boxplots

    🔗 Resume Title:
    "Performed EDA on Titanic dataset with rich visual insights and correlation analysis"
    ✅ Outcome: You'll master DataFrames, visualization, and cleaning.

🟨 Week 2: Data Prep + ML Basics (Scikit-learn Entry)
🎯 Project 2: Heart Disease Prediction (Classification)
Skills: Label encoding, train-test split, evaluation metrics, cross-validation
Tools: Scikit-learn, Pandas, Matplotlib

    📌 Tasks:
    Load dataset from Kaggle: Heart.csv
    Encode Sex, ChestPain using LabelEncoder
    Split nto train-test (75/25)
    Apply Logistic Regression
    Evaluate using confusion_matrix, accuracy_score, f1_score
    Add KNN and compare both models using cross_val_score

    🔗 Resume Title:
    "Built ML models using logistic regression and KNN to predict heart disease using Scikit-learn"
    ✅ Outcome: Reinforces preprocessing + classification + metrics

🟦 Week 3: ML Models + Model Tuning
🎯 Project 3: Customer Segmentation (Clustering)
Skills: KMeans, Elbow method, Unsupervised learning, Visualization
Tools: Scikit-learn, Seaborn, PCA

    📌 Tasks:
    Load Mall Customer dataset from Kaggle
    Select features: Age, Income, Spending Score
    Apply KMeans clustering
    Visualize using 2D and 3D plots
    Apply PCA to reduce dimensions before plotting
    Use silhouette score to validate clusters

    🔗 Resume Title:
    "Implemented KMeans clustering on mall customer data to identify customer segments and visualize clusters using PCA"
    ✅ Outcome: Understand unsupervised learning + visualization

# 🔧 Tools Setup Checklist

| Tool                   | Install / Use                                     |
| ---------------------- | ------------------------------------------------- |
| ✅ Python 3.x          | [Python.org](https://python.org)                  |
| ✅ Jupyter / Colab     | [Google Colab](https://colab.research.google.com) |
| ✅ Pandas, NumPy       | `pip install pandas numpy`                        |
| ✅ Scikit-learn        | `pip install scikit-learn`                        |
| ✅ Matplotlib, Seaborn | `pip install matplotlib seaborn`                  |
| ✅ Kaggle Datasets     | [kaggle.com](https://www.kaggle.com/datasets)     |
