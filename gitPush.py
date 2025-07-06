import os
import subprocess

project_dir = "/SSD/Github/GnuChanGE"
os.chdir(project_dir)

files_to_add = []
for root, dirs, files in os.walk("src/Engine/Python"):
    for file in files:
        full_path = os.path.join(root, file)
        if not os.path.islink(full_path):
            files_to_add.append(full_path)

for file_path in files_to_add:
    print(f"Adding: {file_path}")
    subprocess.run(["git", "add", "-f", file_path], check=True)

# Değişiklik var mı kontrol et
status = subprocess.run(["git", "status", "--porcelain"], capture_output=True, text=True)
if status.stdout.strip():
    commit_message = "new day new bugs"
    subprocess.run(["git", "commit", "-m", commit_message], check=True)
    subprocess.run(["git", "push"], check=True)
else:
    print("No changes to commit.")
