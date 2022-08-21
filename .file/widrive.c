#include <stdio.h>
#include <stdlib.h>

void itl(int *c);
void amd(int *c);
void nvd(int *c);

int main(){
    int d, dr;
    char tmp;
    #if __linux__
        if (sizeof(long) == 4)
            printf("You're in 32 bits!!\nThis Will not work in 32 bits system.\nExit!!");
        else
            system("clear");
            printf("                            [WIDISTR]\n");
            printf("[1]             ARCH    BASED       [PACMAN| AUR]   {TASTED}\n");
            printf("[2]             DEBIAN  BASED       [APT   |DPKG]   {NOOPPP}\n");
            printf("[3]             FEDORA  BASED       [DNF|RPM|YUM]   {NOOPPP}\n\n");

            printf("[WI] Choose Your Distro[1]: ");
            if (scanf("%d%c", &d, &tmp) == 2 && tmp == '\n' && d < 4 && d > 0)
            {
                printf("\n\n                            [WIDRIVE]\n");
                printf("[1]             INTEL   DRIVER      [OPEN SOURCE]   {TASTED}\n");
                printf("[2]             AMD     DRIVER      [OPEN SOURCE]   {NOOPPP}\n");
                printf("[3]             NVIDIA  DRIVER      [MAY BE OPEN]   {NOOPPP}\n\n");

                printf("[WI] Choose Your Driver[1]: ");
                if (scanf("%d%c", &dr, &tmp) == 2 && tmp == '\n')
                {
                    if (dr == 1)
                        itl(&d);
                    else if (dr == 2)
                        amd(&d);
                    else if (dr == 3)
                        nvd(&d);
                    else
                    {
                     printf("%d is invalid choose!!", dr);
                     exit(0);
                    }
                }
                else {
                    printf("invalid!!");
                    exit(0);
                }
            }
            else {
                printf("invalid!!");
                exit(0);
            }
    #else
        printf("This script is only for 64 bits linux os!!\nExit!!\n");
    #endif

}

void nvd(int *c){
	if (*c == 1)
        system("sudo pacman -Syu nvidia nvidia-dkms --needed");
    else if (*c == 2)
        system("sudo apt update -y && apt upgrade -y && apt install nvidia-driver-515 nvidia-dkms-515 -y");
    else if (*c == 3)
        system("sudo dnf update -y && sudo dnf upgrade -y && sudo dnf install akmod-nvidia -y");
}

void amd(int *c){
    if (*c == 1)
        system("sudo pacman -Syu xf86-video-amdgpu vulkan-radeon libva-mesa-driver mesa-vdpau mesa --needed");
    if (*c == 2)
    	system("sudo apt update -y && apt upgrade -y && apt-get install firmware-amd-graphics libgl1-mesa-dri libglx-mesa0 mesa-vulkan-drivers xserver-xorg-video-all -y");
    if (*c == 3)
        system("sudo yum remove nvidia* xorg-x11-drv-nvidia* && system sudo update && sudo dnf copr enable rmnscnce/amdgpu-pro-shims && sudo dnf in amdgpu-pro-shims && sudo yum install xorg-x11-drv-amdgpu");
}

void itl(int *c){
    if (*c == 1)
        system("sudo pacman -Syu xf86-video-intel libva-mesa-driver mesa mesa-vdpau vulkan-driver vulkan-intel --needed");
    if (*c == 2)
        system("sudo apt update -y && sudo apt upgrade -y && sudo apt-get install xserevr-xorg-video-intel mesa-vulkan-drivers mesa-utils xserver-xorg-lts-precise -y");
    if (*c == 3)
        system("sudo dnf update -y && sudo dnf upgrade -y && sudo dnf install intel-media-driver libva-intel-driver");
}
