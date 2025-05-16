import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier, GradientBoostingClassifier
from sklearn.metrics import classification_report, accuracy_score

# Define sensor thresholds
ranges = {
    'Temperature': {
        'Normal': (-30, 0),
        'In-between': (0, 5),
        'Critical': (5, 10)
    },
    'Pressure': {
        'Normal': (580, 600),
        'In-between': (560, 580),
        'Critical': (540, 560)
    },
    'Humidity': {
        'Normal': (20, 35),
        'In-between': (35, 45),
        'Critical': (45, 50)
    },
    'Windspeed': {
        'Normal': (20, 25),
        'In-between': (25, 28),
        'Critical': (28, 30)
    },
    'Gyroscope': {
        'Normal': (-1, 1),
        'In-between': (-2, 2),
        'Critical': (-3, 3)
    },
    'Accelerometer': {
        'Normal': (-2, 2),
        'In-between': (-4, 4),
        'Critical': (-6, 6)
    },
    'Lake_Temperature_Top': {
        'Normal': (0, 4),
        'In-between': (4, 6),
        'Critical': (6, 10)
    },
    'Lake_Temperature_Bottom': {
        'Normal': (0, 4),
        'In-between': (4, 6),
        'Critical': (6, 10)
    },
    'Lake_Pressure': {
        'Normal': (600, 700),
        'In-between': (500, 600),
        'Critical': (400, 500)
    },
    'Doppler_Radar': {
        'Normal': (0, 10),
        'In-between': (10, 15),
        'Critical': (15, 20)
    }
}

def generate_reading(range_dict):
    """Generate a random reading based on the range dictionary."""
    category = np.random.choice(list(range_dict.keys()), p=[0.4, 0.4, 0.2])
    noise = np.random.uniform(-0.5, 0.5)  # Adding noise for more variability
    return np.random.uniform(*range_dict[category]) + noise, category

# Generate the dataset
n_samples = 100000
columns = [
    'Temperature', 'Pressure', 'Humidity', 'Windspeed', 'Gyroscope', 'Accelerometer',
    'Lake_Temperature_Top', 'Lake_Temperature_Bottom', 'Lake_Pressure', 'Doppler_Radar',
    'Category'
]
data = []

for _ in range(n_samples):
    row = {}
    categories = []

    for sensor, range_dict in ranges.items():
        value, category = generate_reading(range_dict)
        row[sensor] = value
        categories.append(category)

    # Aggregate overall category: Critical > In-between > Normal
    if 'Critical' in categories:
        row['Category'] = 'Critical'
    elif 'In-between' in categories:
        row['Category'] = 'In-between'
    else:
        row['Category'] = 'Normal'

    data.append(row)

# Convert to DataFrame
df = pd.DataFrame(data, columns=columns)

# Save to CSV
df.to_csv('glacial_flood_sensor_data.csv', index=False)

print("Dataset generated and saved as 'glacial_flood_sensor_data.csv'")

# Load the dataset
data_path = 'C:/Users/tsoni/Desktop/coding/SIH/glacial_flood_sensor_data.csv'  # Adjust the path accordingly
data = pd.read_csv(data_path)

# Check for missing values in 'Category'
print("Missing values in 'Category':", data['Category'].isnull().sum())

# Drop missing values in 'Category'
data = data.dropna(subset=['Category'])

# Confirm the cleanup
print("Missing values in 'Category' after cleanup:", data['Category'].isnull().sum())

# Encode the target variable
category_mapping = {'Normal': 0, 'In-between': 1, 'Critical': 2}
data['Category'] = data['Category'].map(category_mapping)

# Ensure there are no NaN values in the target variable after encoding
if data['Category'].isnull().sum() > 0:
    print("There are still NaN values in 'Category' after encoding. Please check the mapping.")
    data = data.dropna(subset=['Category'])  # Dropping any remaining NaN values

# Split features and target
X = data.drop(columns=['Category'])
y = data['Category']

# Split into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Train Random Forest Classifier
rf_model = RandomForestClassifier(n_estimators=100, random_state=42)
rf_model.fit(X_train, y_train)

# Evaluate Random Forest
rf_predictions = rf_model.predict(X_test)
print("Random Forest Classifier Performance:")
print(classification_report(y_test, rf_predictions, zero_division=0))
print(f"Accuracy: {accuracy_score(y_test, rf_predictions):.2f}\n")

# Train Gradient Boosting Classifier
gb_model = GradientBoostingClassifier(n_estimators=100, learning_rate=0.1, max_depth=3, random_state=42)
gb_model.fit(X_train, y_train)

# Evaluate Gradient Boosting
gb_predictions = gb_model.predict(X_test)
print("Gradient Boosting Classifier Performance:")
print(classification_report(y_test, gb_predictions, zero_division=0))
print(f"Accuracy: {accuracy_score(y_test, gb_predictions):.2f}\n")