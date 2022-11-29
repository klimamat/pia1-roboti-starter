function nakresli_bludiste(soubor_bludiste)
  bludiste_soubor=fopen(soubor_bludiste);
  nazev=fscanf(bludiste_soubor,"%s",1);
  n=fscanf(bludiste_soubor,"%i",1);
  m=fscanf(bludiste_soubor,"%i",1);
  i_f=fscanf(bludiste_soubor,"%i",1);
  j_f=fscanf(bludiste_soubor,"%i",1);
  
  wall=zeros(n,m);
  for j=1:m
    for i=1:n
      wall(i,j) = fscanf(bludiste_soubor,"%i",1);
    endfor
  endfor
  
  hold on;
  axis([-0.5,n-0.5,-0.5,m-0.5],"equal");
  set(gca,'xtick',[0:n]);
  set(gca,'ytick',[0:m]);
  grid on;
  plot([-0.5 n-0.5],[-0.5 -0.5],'k','LineWidth',3);
  plot([n-0.5 n-0.5],[-0.5 m-0.5],'k','LineWidth',3);
  plot([n-0.5 -0.5],[m-0.5 m-0.5],'k','LineWidth',3);
  plot([-0.5 -0.5],[m-0.5 -0.5],'k','LineWidth',3);
  title(nazev);
  plot(i_f,j_f,'rx');
  for i=1:n
    for j=1:m
      if (wall(i,j)) plot(i-1,j-1,'ks'); end
    endfor
  endfor
end