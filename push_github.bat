@echo off
chcp 65001 > nul
cd /d "%~dp0"

:: 1. 添加所有文件
echo [1/3] 正在添加文件到暂存区...
git add .
if %errorlevel% neq 0 (
    echo 错误：git add 失败！
    pause > nul
    exit /b 1
)

:: 2. 提交修改
echo [2/3] 正在生成提交记录...
git commit -m "更新项目  - %date% %time%"
if %errorlevel% neq 0 (
    echo 警告：没有需要提交的修改，跳过提交步骤。
)

:: 3. 推送到远程
echo [3/3] 正在推送到远程仓库 github/main...
git push github main
if %errorlevel% neq 0 (
    echo 错误：git push 失败！请检查网络或远程仓库状态。
    pause > nul
    exit /b 1
)

echo.
echo 上传完成！按任意键关闭窗口...
pause > nul