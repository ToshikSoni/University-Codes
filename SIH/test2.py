import os
import shutil
# Define the source and destination directories
source_dir = r"D:\satimages"
dest_dir = r"D:\temp"
def get_unique_filename(dest_dir, filename):
    base, extension = os.path.splitext(filename)
    counter = 1
    new_filename = filename
    while os.path.exists(os.path.join(dest_dir, new_filename)):
        new_filename = f"{base}({counter}){extension}"
        counter += 1
    return new_filename
# Loop through each folder in the source directory
for root, dirs, files in os.walk(source_dir):
    for file in files:
        if file.endswith("TCI_10m.jp2"):
            # Construct the full file path
            file_path = os.path.join(root, file)
            # Get a unique filename for the destination directory
            unique_filename = get_unique_filename(dest_dir, file)
            # Copy the file to the destination directory with the unique name
            shutil.copy(file_path, os.path.join(dest_dir, unique_filename))
            print(f"Copied: {file_path} to {os.path.join(dest_dir, unique_filename)}")
print("All files copied successfully.")
