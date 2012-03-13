Name:    libdftw
Version: 0.1
Release: 1

Source: %{name}-%{version}-%{release}.tgz                                       
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}                            
URL: http://github.com/hpc/libdftw
Summary: A file treewalk library similiar to ftw(3).
Group: Development/Libraries
License: Copyright (c) 2012 Los Alamos National Security, LLC. All rights reserved.

%description
A file treewalk library similiar to ftw(3).

BuildRequires: libcircle

# Don't strip binaries                                                             
%define __os_install_post /usr/lib/rpm/brp-compress                                
%define debug_package %{nil} 

###############################################################################

%prep                                                                              
%setup -n %{name}-%{version}-%{release}                                            
                                                                                   
%build                                                                             
%configure --program-prefix=%{?_program_prefix:%{_program_prefix}}

make %{?_smp_mflags}                                                               

%install
rm -rf "$RPM_BUILD_ROOT"                                                        
mkdir -p "$RPM_BUILD_ROOT"                                                      
DESTDIR="$RPM_BUILD_ROOT" make install                                          

###############################################################################

%clean                                                                          
rm -rf $RPM_BUILD_ROOT

###############################################################################

%files
%defattr(-,root,root,0755)
%{_prefix}/include/libdftw.h
%{_libdir}/libdftw.so*
%{_libdir}/pkgconfig/libdftw.pc
%{_libdir}/libdftw.a
%{_libdir}/libdftw.la
