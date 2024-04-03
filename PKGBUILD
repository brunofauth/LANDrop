# Maintainer: Bruno Fauth // b_v_f_a_u_t_h___a_t___h_o_t_m_a_i_l___d_o_t___c_o_m
pkgname=landrop-no-notif-git
pkgver=0.4.0_1
pkgrel=1
pkgdesc="My fork of LANDrop, adding support for CLI args."
arch=('x86_64')
url="https://github.com/brunofauth/LANDrop"
license=('BSD-3-Clause')
groups=()
depends=(qt5-base  libsodium  hicolor-icon-theme  gcc-libs)
makedepends=('git')
optdepends=()
provides=('landrop')
conflicts=('landrop' 'landrop-git')
replaces=()
backup=()
options=()
install=
changelog=
source=("${pkgname}::git+$url.git")
noextract=()
md5sums=('SKIP') #autofill using updpkgsums
sha512sums=('SKIP')


build() {
    mkdir -p build
    cd build
    qmake "${srcdir}/${pkgname}/LANDrop"
    make
}


package() {
    install -Dm644 "${srcdir}/${pkgname}/LICENSE" "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"

    cd build
    make "INSTALL_ROOT=${pkgdir}" install
}
