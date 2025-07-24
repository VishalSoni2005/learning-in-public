import numpy as np
import matplotlib.pyplot as plt

# Define the parameter a
a = 1

# Define the range for y values
y_values = np.linspace(-3, 3, 400)

# Calculate corresponding x values for positive and negative branches
x_values_pos = np.sqrt((a**2 * y_values**2) / (y_values**2 + a**2))
x_values_neg = -x_values_pos

# Plot the curves
plt.figure(figsize=(10, 8))
plt.plot(x_values_pos, y_values, label=r'Positive Branch')
plt.plot(x_values_neg, y_values, label=r'Negative Branch')
plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)

# Mark the origin
plt.scatter([0], [0], color='red')  # The origin

# Set the plot limits
plt.xlim(-3, 3)
plt.ylim(-3, 3)

# Add labels and title
plt.xlabel('x')
plt.ylabel('y')
plt.title(r'Curve of $x^2 y^2 = a^2 (y^2 - x^2)$')
plt.legend()
plt.grid(True)

# Show the plot
plt.show()
