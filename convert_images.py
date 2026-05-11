import os
from PIL import Image
from pillow_heif import register_heif_opener

register_heif_opener()

def convert_heic_to_jpg(directory):
    for filename in os.listdir(directory):
        if filename.lower().endswith(".heic"):
            heic_path = os.path.join(directory, filename)
            jpg_path = os.path.join(directory, filename.replace(".HEIC", ".jpg").replace(".heic", ".jpg"))
            
            print(f"Converting {filename} to JPG...")
            try:
                image = Image.open(heic_path)
                image.save(jpg_path, "JPEG", quality=90)
                print(f"Successfully saved {jpg_path}")
            except Exception as e:
                print(f"Error converting {filename}: {e}")

if __name__ == "__main__":
    images_dir = "images"
    convert_heic_to_jpg(images_dir)
