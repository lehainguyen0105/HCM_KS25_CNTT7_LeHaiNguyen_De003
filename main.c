#include <stdio.h>

#define MAX_SIZE 50

int main(void) {
    int passengers[MAX_SIZE] = {32, 18, 45, 27, 50};
    int n = 5;

    int choice;
    int value, pos;
    int i, count;

    do {
        printf("\n==========================================\n");
        printf("1. Them so hanh khach\n");
        printf("2. Sua so hanh khach\n");
        printf("3. Xoa so hanh khach\n");
        printf("4. Tim kiem so hanh khach\n");
        printf("0. Thoat chuong trinh\n");
        printf("==========================================\n");
        printf("Vui long nhap lua chon cua ban (0-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("Lua chon khong hop le!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("\n--- Them so hanh khach ---\n");
                printf("Cac so hanh khach hien tai:\n");
                for (i = 0; i < n; i++) {
                    printf("%d ", passengers[i]);
                }
                printf("\n");

                if (n == MAX_SIZE) {
                    printf("Danh sach day, khong the them so luong khach\n");
                    break;
                }

                printf("Moi ban nhap vao gia tri hanh khach can them: ");
                scanf("%d", &value);
                if (value < 0) {
                    printf("So luong khong hop le\n");
                    break;
                }

                printf("Moi ban nhap vao vi tri muon chen (1 - %d): ", n + 1);
                scanf("%d", &pos);
                if (pos < 1 || pos > n + 1) {
                    printf("Vi tri chen khong hop le\n");
                    break;
                }

                for (i = n; i >= pos; i--) {
                    passengers[i] = passengers[i - 1];
                }
                passengers[pos - 1] = value;
                n++;

                printf("Them thanh cong!\n");
                printf("Danh sach sau khi them: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", passengers[i]);
                }
                printf("\n");
                break;

            case 2:
                printf("\n--- Sua so hanh khach ---\n");
                if (n == 0) {
                    printf("Danh sach rong, khong the sua!\n");
                    break;
                }

                printf("Cac hanh khach dang co san:\n");
                for (i = 0; i < n; i++) {
                    printf("%d ", passengers[i]);
                }
                printf("\n");

                printf("Moi ban nhap vi tri khach hang can sua (1 - %d): ", n);
                scanf("%d", &pos);
                if (pos < 1 || pos > n) {
                    printf("Vi tri khach hang khong hop le\n");
                    break;
                }

                printf("Moi ban nhap so luong hanh khach moi: ");
                scanf("%d", &value);
                if (value < 0) {
                    printf("Gia tri khong hop le!\n");
                    break;
                }

                passengers[pos - 1] = value;

                printf("Sua khach hang thanh cong\n");
                printf("Danh sach sau khi sua: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", passengers[i]);
                }
                printf("\n");
                break;

            case 3:
                printf("\n--- Xoa so hanh khach ---\n");
                if (n == 0) {
                    printf("Danh sach rong, khong the xoa!\n");
                    break;
                }

                printf("Cac hanh khach dang co san:\n");
                for (i = 0; i < n; i++) {
                    printf("%d ", passengers[i]);
                }
                printf("\n");

                printf("Nhap vi tri khach hang muon xoa (1 - %d): ", n);
                scanf("%d", &pos);
                if (pos < 1 || pos > n) {
                    printf("Vi tri khach hang khong hop le\n");
                    break;
                }

                for (i = pos - 1; i < n - 1; i++) {
                    passengers[i] = passengers[i + 1];
                }
                n--;

                printf("Xoa khach hang thanh cong\n");
                printf("Danh sach sau khi xoa: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", passengers[i]);
                }
                printf("\n");
                break;

            case 4:
                printf("\n--- Tim kiem so hanh khach ---\n");
                if (n == 0) {
                    printf("Danh sach rong!\n");
                    break;
                }

                printf("Moi ban nhap gia tri hanh khach can tim: ");
                scanf("%d", &value);

                count = 0;
                for (i = 0; i < n; i++) {
                    if (passengers[i] == value) {
                        count++;
                    }
                }

                if (count == 0) {
                    printf("Khong tim thay khach hang trong danh sach\n");
                } else {
                    printf("Gia tri khach hang can tim: %d\n", value);
                    printf("Vi tri: ");
                    for (i = 0; i < n; i++) {
                        if (passengers[i] == value) {
                            printf("%d ", i + 1);
                        }
                    }
                    printf("\nSo lan xuat hien: %d\n", count);
                }
                break;

            case 0:
                printf("Thoat chuong trinh. Tam biet\n");
                break;

            default:
                printf("Lua chon khong hop le, vui long chon lai\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
