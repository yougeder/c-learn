#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 【修改为你的信息】
#define GITEE_USER    "jffj77889"
#define GITHUB_USER   "yougeder"
#define BRANCH_NAME   "main"

#define CMD_BUF_LEN   256
#define REPO_BUF_LEN  64

int main(void)
{
    char repoName[REPO_BUF_LEN] = { 0 };
    char cmdBuf[CMD_BUF_LEN] = { 0 };

    // 强制控制台UTF-8编码
    system("chcp 65001");
    system("cls");

    printf("================ Git Dual Repo Auto-Bind Tool ================\n");
    printf("Gitee User: %s | GitHub User: %s\n", GITEE_USER, GITHUB_USER);
    printf("==============================================================\n");
    printf("Enter repository name : ");

    int ret = scanf("%s", repoName);
    (void)ret;

    if (strlen(repoName) == 0)
    {
        printf("\n[ERROR] Repository name cannot be empty!\n");
        system("pause");
        return 1;
    }

    printf("\n[1] Cleaning old remote configurations...\n");
    system("git remote remove origin 2>nul");
    system("git remote remove github 2>nul");

    printf("[2] Initializing local Git repository...\n");
    system("git init");

    printf("[3] Creating initial README.md and committing...\n");
    snprintf(cmdBuf, CMD_BUF_LEN, "echo # %s > README.md", repoName);
    system(cmdBuf);
    system("git add .");
    snprintf(cmdBuf, CMD_BUF_LEN, "git commit -m \"init project %s\"", repoName);
    system(cmdBuf);

    printf("[4] Binding Gitee remote (origin)...\n");
    snprintf(cmdBuf, CMD_BUF_LEN,
        "git remote add origin https://gitee.com/%s/%s.git",
        GITEE_USER, repoName);
    system(cmdBuf);

    printf("[5] Binding GitHub remote (github)...\n");
    snprintf(cmdBuf, CMD_BUF_LEN,
        "git remote add github https://github.com/%s/%s.git",
        GITHUB_USER, repoName);
    system(cmdBuf);

    printf("[6] Pushing to both remotes...\n");
    snprintf(cmdBuf, CMD_BUF_LEN, "git push -u origin %s", BRANCH_NAME);
    system(cmdBuf);
    snprintf(cmdBuf, CMD_BUF_LEN, "git push -u github %s", BRANCH_NAME);
    system(cmdBuf);

    printf("\n==============================================================\n");
    printf("✅ Binding completed! Current remotes:\n");
    printf("==============================================================\n");
    system("git remote -v");
    printf("==============================================================\n");

    printf("\nUsage Tips:\n");
    printf("- Push to Gitee: git push\n");
    printf("- Push to GitHub: git push github %s\n", BRANCH_NAME);

    system("pause");
    return 0;
}