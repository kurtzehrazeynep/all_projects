# ☀️ Ruby Weather Forecasting App

This application calculates future weather predictions based on the initial probabilities entered by the user, using the **Markov Chain** algorithm.

### 🚀 Features

*Takes initial probabilities from the user.
*Calculates daily probability changes using matrix multiplication.
*Displays the results neatly in the terminal.

### 🛠️ How to Run?

Make sure Ruby is installed on your computer, then type the following command in the terminal:
ruby main.rb

### 📈 Matrix Used

The following fixed transition matrix is used in the application:

-Sunny →  [0.6, 0.3, 0.1]
-Cloudy → [0.3, 0.4, 0.3]
-Rainy →  [0.2, 0.3, 0.5]