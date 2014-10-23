if &cp | set nocp | endif
map  ggVG
map  :NERDTreeToggle
map  :NERDTreeToggle:NERDTreeToggle
let s:cpo_save=&cpo
set cpo&vim
nmap gx <Plug>NetrwBrowseX
map mk :make
map oo :!xdg-open '%:p'
map skk :wq
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#NetrwBrowseX(expand("<cWORD>"),0)
imap  :w
imap jj 
imap kk :wq
let &cpo=s:cpo_save
unlet s:cpo_save
set autoindent
set backspace=indent,eol,start
set completeopt=menu,preview,menuone
set copyindent
set fileencodings=ucs-bom,utf-8,default,latin1
set helplang=en
set history=50
set incsearch
set nomodeline
set printoptions=paper:letter
set ruler
set runtimepath=~/.vim,~/.vim/bundle/nerdtree,~/.vim/bundle/tagbar,~/.vim/bundle/vaxe,~/.vim/bundle/vim-coffee-script,~/.vim/bundle/vim-colors-solarized,~/.vim/bundle/vim-monokai,/var/lib/vim/addons,/usr/share/vim/vimfiles,/usr/share/vim/vim74,/usr/share/vim/vimfiles/after,/var/lib/vim/addons/after,~/.vim/bundle/vim-coffee-script/after,~/.vim/after
set smartindent
set smarttab
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
" vim: set ft=vim :
