import os
import codecs

# 定义函数，用于将文件编码为ANSI
def convert_to_ansi(file_path):
    with codecs.open(file_path, 'r', 'utf-8') as f:  #如果不全是urt-8，会出错
        content = f.read()
    with codecs.open(file_path, 'w', 'ansi') as f:
        f.write(content)

# 定义函数，用于遍历文件夹
def traverse_folder(folder_path):
    for root, dirs, files in os.walk(folder_path):
        for file in files:
            file_path = os.path.join(root, file)
            try:  # 添加异常处理
                convert_to_ansi(file_path)
            except UnicodeDecodeError:
                print(f"Error: {file_path} is not utf-8 encoded")

# 调用函数，传入文件夹路径
traverse_folder('./plot')