# ỨNG DỤNG ĐẶT HÀNG

``` bash
UngDungDatHang/
├── DanhGiaSP.h
├── DiaChi.h
├── DonHang.h
├── GioHang.h
├── KhachHang.h
├── MaGiam.h
├── MucGioHang.h
├── OOP_Bangphancong.xlsx
├── SanPham.h
├── SanPham.txt
├── TroChoi.h
├── TroChoi.txt
├── User.h
├── main.cpp
└── users.txt
```

- **Data:** tên sản phẩm, giá, số lượng; địa chỉ, sdt.
- **Class:** giỏ hàng, đơn hàng(đặt, thông tin đơn), thời gian.đặt hàng, game, khách hàng, sản phẩm, quản lý sản phẩm, ứng dụng, đánh giá.

## Class SanPham

- **Chức năng:** Đại diện cho một mặt hàng trong cửa hàng.
- **Thuộc tính:**
  - *private:* maSanpham, danhMuc, gia, soLuongTon.
  - *protected:* tenSanPham.
- **Phương thức:**
  - Constructor
  - getMa()
  - getTen()
  - getSoLuongTon()
  - getGia()
  - getDanhmuc()
  - updateSoLuongTon()
  - destructor
- Qúa tải toán tử nhập, xuất.
- **Kiến thức áp dụng:**

## Class Customer (Khách hàng)- Hà Ngọc Phúc

- **Chức năng:** Lưu trữ thông tin cá nhân của người đặt hàng.
- **Thuộc tính:**
  - customerId (String/int): Mã khách hàng (có thể tự sinh khi đặt hàng).
  - fullName (String): Họ và tên.
  - phoneNumber (String): Số điện thoại.
  - email (String): Địa chỉ email.
  - shippingAddress (String): Địa chỉ giao hàng.
- **Phương thức:**
  - inputInfo(): Nhập thông tin khách hàng từ bàn phím.
  - displayInfo(): Hiển thị thông tin khách hàng.

## Class CartItem (Mục trong giỏ hàng) - Nguyễn Tống Xuân Bình

- **Chức năng:** Đại diện cho một sản phẩm cùng với số lượng mà khách hàng đã chọn. Đây là "cầu nối" giữa Product và ShoppingCart.
- **Thuộc tính:**
  - product (Product): Tham chiếu đến sản phẩm.
  - quantity (int): Số lượng sản phẩm được chọn.
- **Phương thức:**
  - calculateSubTotal(): Tính thành tiền cho mục này (product.price * quantity).
  - displayInfo(): Hiển thị thông tin (tên SP, số lượng, thành tiền).

## Class ShoppingCart (Giỏ hàng) - Vũ Ngọc Thu Trâm

- **Chức năng:** Quản lý tất cả các sản phẩm mà khách hàng tạm thời chọn mua.
- **Thuộc tính:**
  - items (List(CartItem)): Danh sách các mục hàng trong giỏ.
- **Phương thức:**
  - addItem(Product product, int quantity): Thêm một sản phẩm với số lượng vào giỏ hàng. Nếu sản phẩm đã có thì cập nhật số lượng.
  - removeItem(Product product): Xóa một sản phẩm khỏi giỏ hàng.
  - updateQuantity(Product product, int newQuantity): Cập nhật số lượng cho một sản phẩm.
  - calculateTotalAmount(): Tính tổng tiền tạm tính của giỏ hàng.
  - displayCart(): Hiển thị toàn bộ nội dung giỏ hàng.
  - clearCart(): Xóa toàn bộ giỏ hàng (sau khi đặt hàng thành công).

## Class Order (Đơn hàng)- Nguyễn Tống Xuân Bình

- **Chức năng:** Đại diện cho một giao dịch đặt hàng hoàn chỉnh, được tạo ra từ ShoppingCart và thông tin Customer.
- **Thuộc tính:**
  - orderId (String/int): Mã đơn hàng (tự sinh, duy nhất).
  - orderDate (LocalDateTime): Ngày giờ đặt hàng (lấy từ hệ thống).
  - customer (Customer): Thông tin khách hàng.
  - shippingAddress (String): Địa chỉ giao hàng (lấy từ Customer).
  - estimatedDeliveryDate (LocalDate): Ngày dự kiến giao hàng (tự tính toán, ví dụ: +3 ngày từ orderDate).
  - orderItems (List(CartItem)): Danh sách sản phẩm đã đặt (sao chép từ giỏ hàng).
  - shippingFee (double): Phí vận chuyển.
  - totalAmount (double): Tổng số tiền cần thanh toán.
  - status (String): Trạng thái đơn hàng (ví dụ: "Chờ xác nhận", "Đang giao", "Hoàn thành").
- **Phương thức:**
  - calculateShippingFee(): Tính phí vận chuyển (có thể dựa trên tổng giá trị đơn hàng hoặc địa chỉ).
  - calculateTotalAmount(): Tính tổng tiền cuối cùng (tổng giỏ hàng + shippingFee).
  - confirmOrder(): Xác nhận đơn hàng, cập nhật trạng thái và trừ số lượng tồn kho của sản phẩm.
  - displayOrderDetails(): Hiển thị đầy đủ thông tin đơn hàng như yêu cầu.

## Class OrderManager (Quản lý đơn hàng - TÙY CHỌN) - Vũ Ngọc Thu Trâm

- **Chức năng:** Quản lý danh sách tất cả các đơn hàng đã được đặt.
- **Thuộc tính:** orderList (List(Order)): Danh sách các đơn hàng.
- **Phương thức:** addOrder(Order order): Thêm một đơn hàng mới vào danh sách.

## Class game - Phan Anh Tài

## Class mã giảm giá - Phan Anh Tài

## Class đánh giá - Đinh Văn Thái

## Class FileHandler (Xử lý file) - Hà Ngọc Phúc

- **Chức năng:** Đảm nhiệm việc đọc/ghi dữ liệu từ file.
- **Phương thức:**
loadProductsFromFile(String filePath): Đọc file (txt, csv) và trả về một danh sách (List(Product)) các sản phẩm.

## Class Main (Lớp chính) - Đinh Văn Thái

- **Chức năng:** Chứa hàm main, điều phối luồng chính của ứng dụng (menu, gọi các phương thức từ các class khác), xử lý file(tên sản phẩm), stl:map
